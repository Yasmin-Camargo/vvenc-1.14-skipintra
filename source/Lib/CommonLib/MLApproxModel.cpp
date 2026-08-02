#include "MLApproxModel.h"
#include "CodingStructure.h"
#include "Picture.h"
#include "Unit.h"
#include "MLFeaturesManager.h"

#include "decision_tree_single_mdecision_tree_All_Blocks-issplit.h"
#include "decision_tree_single_mdecision_tree_All_Blocks-intrakept.h"
#include <chrono>

#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>

namespace vvenc {

std::atomic<long long> MLApproxModel::countTotalEval{0};
std::atomic<long long> MLApproxModel::countIsSplit{0};
std::atomic<long long> MLApproxModel::countNotIntraKept{0};
std::atomic<long long> MLApproxModel::countLossless{0};
std::atomic<long long> countFeatureExtractionTimeUs{0}; // Us = Microseconds

namespace
{
std::vector<double> buildIsSplitVector( const MLFeatureData& data )
{
    std::vector<double> f;
    f.reserve(10);
    f.push_back((double)data.interCost);
    f.push_back((double)data.csInterHad);
    f.push_back((double)data.refLineVariance);
    f.push_back((double)data.refLineRange);
    f.push_back((double)data.numIntraCiipNeighbors);
    f.push_back((double)data.varMismatch);
    f.push_back((double)data.distCenterY);
    f.push_back((double)data.splittingDensity);
    f.push_back((double)data.blkMax);
    f.push_back((double)data.blkRange);
    return f;
}

std::vector<double> buildIntraKeptVector( const MLFeatureData& data )
{
    std::vector<double> f;
    f.reserve(13);
    f.push_back((double)data.frameLevel);
    f.push_back((double)data.splitSeries);
    f.push_back((double)data.interHadPerPixel);
    f.push_back((double)data.refLineRange);
    f.push_back((double)data.numIntraCiipNeighbors);
    f.push_back((double)data.leftDepth);
    f.push_back((double)data.relativeBlockArea);
    f.push_back((double)data.deltaQP);
    f.push_back((double)data.contrastRatio);
    f.push_back((double)data.directionalDominance);
    f.push_back((double)data.varMismatch);
    f.push_back((double)data.blkStdV);
    f.push_back((double)data.blkRange);
    return f;
}
} // namespace

bool MLApproxModel::evaluateSkipIntra( const CodingStructure& cs, const CodingUnit& cu, double interCost )
{
    if( cs.slice->isIntra() || cu.chType == vvenc::CH_C )
    {
        return false;
    }

    //return true; // Test: skipping the intra-search for all evaluated blocks

    countTotalEval++;

    auto start = std::chrono::high_resolution_clock::now();

    MLFeatureData featData = MLFeaturesManager::extractFeatures(cs, cu, interCost);

    auto end = std::chrono::high_resolution_clock::now();
    countFeatureExtractionTimeUs += std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    const auto featuresSplit = buildIsSplitVector( featData );
    int isSplit = decision_tree_single_mdecision_tree_All_Blocks_issplit( featuresSplit );
    
    if (isSplit == 1) 
    {
        countIsSplit++;
        return true; 
    }
    
    const auto featuresIntra = buildIntraKeptVector( featData );
    int isIntraKept = decision_tree_single_mdecision_tree_All_Blocks_intrakept( featuresIntra );
    
    if (isIntraKept == 0)
    {
        countNotIntraKept++;
        return true; 
    }

    countLossless++;
    return false;
}

void MLApproxModel::printSummary()
{
    std::cout << "\n=======================================================\n";
    std::cout << "[MLApproxModel] Decision Report\n";
    std::cout << "=======================================================\n";

    if (countTotalEval == 0) {
        std::cout << "No blocks were evaluated by the ML models (Baseline Mode).\n";
        std::cout << "=======================================================\n";
        return;
    }

    double pctSplit = (countIsSplit * 100.0) / countTotalEval;
    double pctNotIntra = (countNotIntraKept * 100.0) / countTotalEval;
    double pctLossless = (countLossless * 100.0) / countTotalEval;
    double pctTotalSkipped = pctSplit + pctNotIntra;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "-------------------------------------------------------\n";
    std::cout << "Total Blocks Evaluated    : " << countTotalEval << " (100.00%)\n";
    std::cout << " -> Skipped Intra (IsSplit): " << countIsSplit << " (" << pctSplit << "%)\n";
    std::cout << " -> Skipped Intra (!Intra) : " << countNotIntraKept << " (" << pctNotIntra << "%)\n";
    std::cout << " -> Evaluated Intra (Kept) : " << countLossless << " (" << pctLossless << "%)\n";
    std::cout << "-------------------------------------------------------\n";
    std::cout << "Summary: " << pctTotalSkipped << "% of the blocks skipped the Intra search.\n";
    std::cout << " -> Total time for feature extraction: " << (countFeatureExtractionTimeUs / 1000.0) << " ms\n";
    std::cout << "=======================================================\n";
}

} // namespace vvenc