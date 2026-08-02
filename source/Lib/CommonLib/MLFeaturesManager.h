#pragma once

#include <fstream>
#include <mutex>
#include <string>

#include "CommonDef.h"


namespace vvenc {

class CodingStructure;
class CodingUnit;

struct MLFeatureData {
  int framePoc;
  int frameLevel;
  int xPos;
  int yPos;
  int blockWidth;
  int blockHeight;
  int blockArea;
  int blockAreaGroup;
  int borderContactMask;

  bool isIntra;

  int cuQp;
  int depth;
  int qtDepth;
  int btDepth;
  long long splitSeries;

  int orientationGroup;
  int aspectRatioGroup;

  double interCost;
  double csInterHad;
  double interHadPerPixel;

  bool availLeft;
  bool availAbove;
  bool leftIsIntra;
  bool aboveIsIntra;
  int leftIntraDir;
  int aboveIntraDir;

  double refLineVariance;
  double refColVariance;
  double refLineMean;
  double refLineRange;

  int ctuPosInCtuX;
  int ctuPosInCtuY;
  bool isFirstLineOfCTU;
  int sliceType;

  int cuMtDepth;
  int cuBtDepth;
  bool canUseMIP;
  bool canUseISP;

  int mpm0;
  double mpmAngularVar;
  int numIntraCiipNeighbors;

  int leftDepth;
  int aboveDepth;
  int leftQtDepth;
  int aboveQtDepth;
  int leftMtDepth;
  int aboveMtDepth;
  int numIntraNeighbors4;
  bool leftIsMIP;
  bool aboveIsMIP;
  int leftISPMode;
  int aboveISPMode;
  double neighborMeanDepth;

  int refIsIntra;
  double refIntraAreaRatio;
  double refBiPredAreaRatio;
  double refMvAvgMagnitude;
  double refMvMagnitudeVar;

  double relativeBlockArea;
  int deltaQP;
  double contrastRatio;
  double directionalDominance;
  double variancePerArea;
  double meanMismatch;
  double varMismatch;
  double coefVariation;
  double refDominance;
  int mpmDelta;
  double distCenterX;
  double distCenterY;
  double boundaryComplexityRatio;
  double splittingDensity;
  double centerFocusWeight;

  double blkPixelMean;
  double blkPixelVariance;
  double blkPixelStdDev;
  double blkPixelSum;
  double blkVarH;
  double blkVarV;
  double blkStdH;
  double blkStdV;
  double blkMin;
  double blkMax;
  double blkRange;

  MLFeatureData()
    : framePoc( 0 ), frameLevel( 0 ), xPos( 0 ), yPos( 0 ), blockWidth( 0 ), blockHeight( 0 ),
      blockArea( 0 ), blockAreaGroup( 0 ), borderContactMask( 0 ), isIntra( false ), cuQp( 0 ),
      depth( 0 ), qtDepth( 0 ), btDepth( 0 ), splitSeries( 0 ), orientationGroup( 0 ),
      aspectRatioGroup( 0 ), interCost( -1.0 ), csInterHad( 0.0 ), interHadPerPixel( -1.0 ),
      availLeft( false ), availAbove( false ), leftIsIntra( false ), aboveIsIntra( false ),
      leftIntraDir( -1 ), aboveIntraDir( -1 ), refLineVariance( 0.0 ), refColVariance( 0.0 ),
      refLineMean( 0.0 ), refLineRange( 0.0 ), ctuPosInCtuX( 0 ), ctuPosInCtuY( 0 ),
      isFirstLineOfCTU( false ), sliceType( 0 ), cuMtDepth( 0 ), cuBtDepth( 0 ),
      canUseMIP( false ), canUseISP( false ), mpm0( -1 ), mpmAngularVar( 0.0 ),
      numIntraCiipNeighbors( 0 ), 
      leftDepth(-1), aboveDepth(-1), leftQtDepth(-1), aboveQtDepth(-1), 
      leftMtDepth(-1), aboveMtDepth(-1), numIntraNeighbors4(0), 
      leftIsMIP(false), aboveIsMIP(false), leftISPMode(0), aboveISPMode(0), 
      neighborMeanDepth(-1.0), refIsIntra(0), refIntraAreaRatio(0.0), 
      refBiPredAreaRatio(0.0), refMvAvgMagnitude(0.0), refMvMagnitudeVar(0.0),
      relativeBlockArea( 0.0 ), deltaQP( 0 ), contrastRatio( 0.0 ),
      directionalDominance( 0.0 ), variancePerArea( 0.0 ), meanMismatch( 0.0 ), varMismatch( 0.0 ),
      coefVariation( 0.0 ), refDominance( 0.0 ), mpmDelta( -1 ), distCenterX( 0.0 ),
      distCenterY( 0.0 ), boundaryComplexityRatio( 0.0 ), splittingDensity( 0.0 ),
      centerFocusWeight( 0.0 ), blkPixelMean( 0.0 ), blkPixelVariance( 0.0 ),
      blkPixelStdDev( 0.0 ), blkPixelSum( 0.0 ), blkVarH( 0.0 ), blkVarV( 0.0 ), blkStdH( 0.0 ),
      blkStdV( 0.0 ), blkMin( 0.0 ), blkMax( 0.0 ), blkRange( 0.0 )
  {}
};

class VVENC_DECL MLFeaturesManager {
private:
  static std::ofstream featFp;
  static std::mutex writeMutex;

  static std::string videoName;
  static std::string encoderPreset;
  static int targetQP;
  static int bitDepth;
  static int frameWidth;
  static int frameHeight;

public:
  static void init( const std::string& vName, const std::string& preset, int tQp, int bDepth, int fWidth, int fHeight );
  
  static void finish();
  
  static MLFeatureData extractFeatures( const vvenc::CodingStructure& cs, const vvenc::CodingUnit& cu, double bestCostInter );
  static void saveFeatures( const MLFeatureData& data );

  static int getFrameWidth() { return frameWidth; }
  static int getFrameHeight() { return frameHeight; }
  static int getTargetQP() { return targetQP; }
};

}