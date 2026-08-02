#include "MLFeaturesManager.h"
#include "CodingStructure.h"
#include "Picture.h"
#include "Reshape.h"
#include "Unit.h"
#include "UnitTools.h"
#include "MLApproxModel.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

namespace vvenc {

std::ofstream MLFeaturesManager::featFp;
std::mutex MLFeaturesManager::writeMutex;

std::string MLFeaturesManager::videoName;
std::string MLFeaturesManager::encoderPreset;
int MLFeaturesManager::targetQP;
int MLFeaturesManager::bitDepth;
int MLFeaturesManager::frameWidth;
int MLFeaturesManager::frameHeight;

namespace
{
struct BufferStats
{
  double mean = 0.0;
  double variance = 0.0;
  double range = 0.0;
};

BufferStats calcBufferStats( const vvenc::CPelBuf& buf )
{
  BufferStats stats;
  if( buf.buf == nullptr || buf.width <= 0 || buf.height <= 0 ) return stats;

  const int sampleCount = buf.width * buf.height;
  double sum = 0.0, sumSq = 0.0;
  const vvenc::Pel* pBuf = buf.buf;
  double minVal = static_cast<double>( pBuf[0] );
  double maxVal = minVal;

  for( int y = 0; y < buf.height; y++ )
  {
    for( int x = 0; x < buf.width; x++ )
    {
      const double value = static_cast<double>( pBuf[x] );
      sum += value; sumSq += value * value;
      minVal = std::min( minVal, value );
      maxVal = std::max( maxVal, value );
    }
    pBuf += buf.stride;
  }

  stats.mean = sum / sampleCount;
  stats.variance = std::max( 0.0, ( sumSq / sampleCount ) - ( stats.mean * stats.mean ) );
  stats.range = maxVal - minVal;
  return stats;
}

void fillImageFeaturesFromBuf( const vvenc::CPelBuf& buf, MLFeatureData& data )
{
  if( buf.buf == nullptr || buf.width <= 0 || buf.height <= 0 ) return;

  const int sampleCount = buf.width * buf.height;
  std::vector<double> colSum( buf.width, 0.0 );
  std::vector<double> colSumSq( buf.width, 0.0 );

  const vvenc::Pel* pBuf = buf.buf;
  double sum = 0.0, sumSq = 0.0;
  double rowVarSum = 0.0, colVarSum = 0.0, colStdSum = 0.0;
  double minVal = static_cast<double>( pBuf[0] );
  double maxVal = minVal;

  for( int y = 0; y < buf.height; y++ )
  {
    double rowSum = 0.0, rowSumSq = 0.0;
    for( int x = 0; x < buf.width; x++ )
    {
      const double value = static_cast<double>( pBuf[x] );
      sum += value; sumSq += value * value;
      rowSum += value; rowSumSq += value * value;
      colSum[x] += value; colSumSq[x] += value * value;
      minVal = std::min( minVal, value );
      maxVal = std::max( maxVal, value );
    }
    const double rowMean = rowSum / buf.width;
    const double rowVar = std::max( 0.0, ( rowSumSq / buf.width ) - ( rowMean * rowMean ) );
    rowVarSum += rowVar;
    pBuf += buf.stride;
  }

  for( int x = 0; x < buf.width; x++ )
  {
    const double colMean = colSum[x] / buf.height;
    const double colVar = std::max( 0.0, ( colSumSq[x] / buf.height ) - ( colMean * colMean ) );
    colVarSum += colVar;
    colStdSum += std::sqrt( colVar );
  }

  double blkPixelMean = sum / sampleCount;
  double blkPixelVariance = std::max( 0.0, ( sumSq / sampleCount ) - ( blkPixelMean * blkPixelMean ) );
  double blkVarH = rowVarSum / buf.height;
  double blkVarV = colVarSum / buf.width;

  data.blkMax = maxVal;
  data.blkRange = maxVal - minVal;
  data.blkStdV = colStdSum / buf.width;
  data.contrastRatio = data.blkRange / ( blkPixelMean + 1.0 );
  data.directionalDominance = std::abs( blkVarH - blkVarV ) / ( blkVarH + blkVarV + 1.0 );
  data.varMismatch = std::abs( blkPixelVariance - data.refLineVariance );
}
} // anonymous namespace

MLFeatureData MLFeaturesManager::extractFeatures( const vvenc::CodingStructure& cs, const vvenc::CodingUnit& cu, double bestCostInter )
{
  MLFeatureData featData;

  featData.interCost = ( bestCostInter >= 1e300 ) ? -1.0 : bestCostInter;
  featData.csInterHad = ( cu.cs->interHad >= 1e18 ) ? -1.0 : static_cast<double>( cu.cs->interHad );
  
  featData.frameLevel = cu.slice->TLayer;
  featData.splitSeries = (long long) cu.splitSeries;
  featData.deltaQP = cu.qp - MLFeaturesManager::getTargetQP();
  featData.splittingDensity = ( cu.mtDepth + cu.btDepth ) / 6.0;

  int blockArea = cu.lwidth() * cu.lheight();
  featData.interHadPerPixel = blockArea > 0 ? featData.csInterHad / (double) blockArea : 0.0;

  if( frameWidth > 0 && frameHeight > 0 )
  {
    featData.relativeBlockArea = (double) blockArea / (double) ( frameWidth * frameHeight );
    const double centerY = frameHeight / 2.0;
    featData.distCenterY = std::abs( cu.ly() + ( cu.lheight() / 2.0 ) - centerY ) / centerY;
  }

  const vvenc::CodingUnit* leftCu = cs.getCURestricted( cu.lumaPos().offset( -1, 0 ), cu, vvenc::CH_L );
  const vvenc::CodingUnit* aboveCu = cs.getCURestricted( cu.lumaPos().offset( 0, -1 ), cu, vvenc::CH_L );

  featData.leftDepth = leftCu ? leftCu->depth : -1;
  
  bool leftIsIntra = leftCu != nullptr && leftCu->predMode == vvenc::PredMode::MODE_INTRA;
  bool aboveIsIntra = aboveCu != nullptr && aboveCu->predMode == vvenc::PredMode::MODE_INTRA;
  featData.numIntraCiipNeighbors = ( leftIsIntra ? 1 : 0 ) + ( aboveIsIntra ? 1 : 0 );

  if( cu.ly() > 0 )
  {
    vvenc::CompArea aboveArea = cu.Y();
    aboveArea.y -= 1;
    aboveArea.height = 1;
    const BufferStats aboveStats = calcBufferStats( cs.picture->getOrigBuf( aboveArea ) );
    featData.refLineVariance = aboveStats.variance;
    featData.refLineRange = aboveStats.range;
  }

  const auto& reshapeData = cs.picture->reshapeData;
  const vvenc::CPelBuf orgBuf = ( cs.picHeader->lmcsEnabled && reshapeData.getCTUFlag() ) ? cs.getRspOrgBuf( cu.Y() ) : cs.getOrgBuf( cu.Y() );

  fillImageFeaturesFromBuf( orgBuf, featData );

  return featData;
}

void MLFeaturesManager::init( const std::string& vName, const std::string& preset, int tQp, int bDepth, int fWidth, int fHeight )
{
  videoName = vName; encoderPreset = preset; targetQP = tQp;
  bitDepth = bDepth; frameWidth = fWidth; frameHeight = fHeight;
}

void MLFeaturesManager::saveFeatures( const MLFeatureData& data )
{
  // Operation ignored
}

void MLFeaturesManager::finish()
{
  vvenc::MLApproxModel::printSummary();
}

} // namespace vvenc