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

std::atomic<long long> countFeatureExtractionTimeUs{0}; 
std::atomic<long long> countTimeIsSplitUs{0};
std::atomic<long long> countTimeIntraKeptUs{0};
std::atomic<long long> MLApproxModel::countTimeIntraSearchUs{0};

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
    if ( cs.slice->isIntra() || cu.chType == vvenc::CH_C ) 
    {
        return false; 
    }

    bool useIsSplit = isIsSplitEnabled();
    bool useIntraKept = isIntraKeptEnabled();

    if (!useIsSplit && !useIntraKept) {
        return false;
    }
    //return true; // Test: skipping the intra-search for all evaluated blocks

    countTotalEval++;

    auto startFeat = std::chrono::high_resolution_clock::now();
    MLFeatureData featData = MLFeaturesManager::extractFeatures(cs, cu, interCost);
    auto endFeat = std::chrono::high_resolution_clock::now();
    countFeatureExtractionTimeUs += std::chrono::duration_cast<std::chrono::microseconds>(endFeat - startFeat).count();

    bool mlDecision = false;
    int isSplit = 0;

    if (useIsSplit)
    {
        const auto featuresSplit = buildIsSplitVector( featData );

        auto startSplit = std::chrono::high_resolution_clock::now();
        isSplit = decision_tree_single_mdecision_tree_All_Blocks_issplit( featuresSplit );
        auto endSplit = std::chrono::high_resolution_clock::now();
        countTimeIsSplitUs += std::chrono::duration_cast<std::chrono::microseconds>(endSplit - startSplit).count();

        if (isSplit == 1)
        {
            countIsSplit++;
            mlDecision = true;
        }
    }

    if (!mlDecision)
    {
        if (useIntraKept)
        {
            const auto featuresIntra = buildIntraKeptVector(featData);

            auto startIntra = std::chrono::high_resolution_clock::now();
            int isIntraKept = decision_tree_single_mdecision_tree_All_Blocks_intrakept(featuresIntra);
            auto endIntra = std::chrono::high_resolution_clock::now();
            countTimeIntraKeptUs += std::chrono::duration_cast<std::chrono::microseconds>(endIntra - startIntra).count();

            if (isIntraKept == 0)
            {
                countNotIntraKept++;
                mlDecision = true;
            }
            else
            {
                countLossless++;
                mlDecision = false;
            }
        }
        else
        {
            countLossless++;
            mlDecision = false; 
        }
    }
    
    return mlDecision;
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

    double timeFeatMs = countFeatureExtractionTimeUs / 1000.0;
    double timeSplitMs = countTimeIsSplitUs / 1000.0;
    double timeIntraMs = countTimeIntraKeptUs / 1000.0;
    double totalTimeMs = timeFeatMs + timeSplitMs + timeIntraMs;
    double timeIntraSearchMs = countTimeIntraSearchUs / 1000.0;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "-------------------------------------------------------\n";
    std::cout << "Model Status:\n";
    std::cout << " -> IsSplit Model      : " << (isIsSplitEnabled() ? "ON" : "OFF") << "\n";
    std::cout << " -> IntraKept Model    : " << (isIntraKeptEnabled() ? "ON" : "OFF") << "\n";
    std::cout << "-------------------------------------------------------\n";
    std::cout << "Total Blocks Evaluated    : " << countTotalEval << " (100.00%)\n";
    std::cout << " -> Skipped Intra (IsSplit): " << countIsSplit << " (" << pctSplit << "%)\n";
    std::cout << " -> Skipped Intra (!Intra) : " << countNotIntraKept << " (" << pctNotIntra << "%)\n";
    std::cout << " -> Evaluated Intra (Kept) : " << countLossless << " (" << pctLossless << "%)\n";
    std::cout << "-------------------------------------------------------\n";
    std::cout << "Time Report (ms):\n";
    std::cout << " -> Feature Extraction     : " << timeFeatMs << " ms\n";
    std::cout << " -> IsSplit Model Inference: " << timeSplitMs << " ms\n";
    std::cout << " -> IntraKept Model Infer. : " << timeIntraMs << " ms\n";
    std::cout << " -> TOTAL INTRA-SEARCH TIME: " << timeIntraSearchMs << " ms\n";
    std::cout << " -> TOTAL ML OVERHEAD      : " << totalTimeMs << " ms\n";
    std::cout << "-------------------------------------------------------\n";
    std::cout << "Summary: " << pctTotalSkipped << "% of the blocks skipped the Intra search.\n";
    std::cout << "=======================================================\n";
}

} // namespace vvenc