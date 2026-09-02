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

std::atomic<long long> MLApproxModel::globalTotalBlocksEvaluated{0};
std::atomic<long long> MLApproxModel::totalIntraBlocksEvaluated{0};
std::atomic<long long> MLApproxModel::intraLumaEvaluated{0};
std::atomic<long long> MLApproxModel::intraChromaEvaluated{0};
std::atomic<long long> MLApproxModel::intraLumaAtFrameLevel0{0};

std::atomic<long long> MLApproxModel::finalIntraKept{0};
std::atomic<long long> MLApproxModel::finalSplit{0};
std::atomic<long long> MLApproxModel::finalOther{0};
std::atomic<long long> MLApproxModel::finalNonLuma{0};

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

void MLApproxModel::incrementIntraBlocks(bool isLumaBlock, bool isFrameLevel0)
{
    totalIntraBlocksEvaluated++;
    if (isLumaBlock) {
        intraLumaEvaluated++;
        if (isFrameLevel0) {
            intraLumaAtFrameLevel0++;
        }
    } else {
        intraChromaEvaluated++;
    }
}

bool MLApproxModel::evaluateSkipIntra( const CodingStructure& cs, const CodingUnit& cu, double interCost )
{
    if (!isSkipEnabled()) {
        return false; // Baseline
    }

    if ( cs.slice->isIntra() || cu.chType == vvenc::CH_C ) 
    {
        return false; 
    }

    if ( isSkipAllIntraEnabled() )
    {
        return true;  // Test: skipping the intra-search for all evaluated blocks
    }

    bool useIsSplit = isIsSplitEnabled();
    bool useIntraKept = isIntraKeptEnabled();

    if (!useIsSplit && !useIntraKept) {
        return false;
    }

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
    std::cout << "         OPTIMIZATION REPORT                 \n";
    std::cout << "=======================================================\n";
    std::cout << "[1] Global Total Blocks Evaluated      : " << globalTotalBlocksEvaluated << "\n";
    
    long long totalIntraEval = intraLumaEvaluated + intraChromaEvaluated;
    double pctTotalIntraEval = globalTotalBlocksEvaluated > 0 ? (totalIntraEval * 100.0) / globalTotalBlocksEvaluated : 0.0;

    double pctFL0 = totalIntraEval > 0 ? (intraLumaAtFrameLevel0 * 100.0) / totalIntraEval : 0.0;
    
    long long totalIntraWithoutFL0 = totalIntraEval - intraLumaAtFrameLevel0;
    double pctWithoutFL0 = totalIntraEval > 0 ? (totalIntraWithoutFL0 * 100.0) / totalIntraEval : 0.0;
    
    long long lumaWithoutFL0 = intraLumaEvaluated - intraLumaAtFrameLevel0;
    double pctLumaWithoutFL0 = totalIntraWithoutFL0 > 0 ? (lumaWithoutFL0 * 100.0) / totalIntraWithoutFL0 : 0.0;
    double pctChroma = totalIntraWithoutFL0 > 0 ? (intraChromaEvaluated * 100.0) / totalIntraWithoutFL0 : 0.0;

    std::cout << "[2] Total Intra Blocks (With FL0)      : " << totalIntraEval 
              << " (" << std::fixed << std::setprecision(2) << pctTotalIntraEval << "% of Global)\n";
    std::cout << "    |- Intra Luma at Frame Level 0     : " << intraLumaAtFrameLevel0 
              << " (" << pctFL0 << "% of Total Intra) [Ignored]\n";
    std::cout << "    |- Total Intra Blocks (Without FL0): " << totalIntraWithoutFL0 
              << " (" << pctWithoutFL0 << "% of Total Intra)\n";
    std::cout << "       |- Luma Evaluated (> FL0)       : " << lumaWithoutFL0 
              << " (" << pctLumaWithoutFL0 << "% of Intra without FL0)\n";
    std::cout << "       |- Chroma Evaluated             : " << intraChromaEvaluated 
              << " (" << pctChroma << "% of Intra without FL0)\n";
    std::cout << "-------------------------------------------------------\n";

    bool masterEnabled = isSkipEnabled();
    bool skipAllEnabled = isSkipAllIntraEnabled();
    bool isSplitEnabledActual = isIsSplitEnabled();
    bool intraKeptEnabledActual = isIntraKeptEnabled();

    std::cout << "Model Status:\n";
    std::cout << " -> ML_SKIP_INTRA (Master) : " << (masterEnabled ? "ON" : "OFF") << "\n";
    
    if (!masterEnabled) {
        std::cout << " -> Skip All Intra         : OFF\n";
        std::cout << " -> IsSplit Model          : OFF\n";
        std::cout << " -> IntraKept Model        : OFF\n";
    } else if (skipAllEnabled) {
        std::cout << " -> Skip All Intra         : ON (Always Skip)\n";
        std::cout << " -> IsSplit Model          : OFF (Bypassed)\n";
        std::cout << " -> IntraKept Model        : OFF (Bypassed)\n";
    } else {
        std::cout << " -> Skip All Intra         : OFF\n";
        std::cout << " -> IsSplit Model          : " << (isSplitEnabledActual ? "ON" : "OFF") << "\n";
        std::cout << " -> IntraKept Model        : " << (intraKeptEnabledActual ? "ON" : "OFF") << "\n";
    }
    std::cout << "-------------------------------------------------------\n";

    if (countTotalEval == 0) {
        if (!masterEnabled) {
            std::cout << "ML models disabled via ML_SKIP_INTRA=0 (Baseline Mode).\n";
        } else if (skipAllEnabled) {
            std::cout << "All valid blocks skipped Intra search due to ML_SKIP_ALL_INTRA=1.\n";
        } else {
            std::cout << "No blocks were evaluated by the ML models.\n";
        }
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
    std::cout << "Total Blocks Filtered by ML (Eval) : " << countTotalEval << " (100.00%)\n";
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

    long long totalFinal = finalIntraKept + finalSplit + finalOther + finalNonLuma;
    double pctFinalIntra = totalFinal > 0 ? (finalIntraKept * 100.0) / totalFinal : 0.0;
    double pctFinalSplit = totalFinal > 0 ? (finalSplit * 100.0) / totalFinal : 0.0;
    double pctFinalOther = totalFinal > 0 ? (finalOther * 100.0) / totalFinal : 0.0;
    double pctFinalNonLuma = totalFinal > 0 ? (finalNonLuma * 100.0) / totalFinal : 0.0;

    std::cout << "FINAL DECISION FOR ALL BLOCKS:\n";
    std::cout << " - Intra Kept Blocks                   : " << finalIntraKept << " (" << pctFinalIntra << "%)\n";
    std::cout << " - Split Blocks                        : " << finalSplit << " (" << pctFinalSplit << "%)\n";
    std::cout << " - Other Blocks (Inter/Skip/etc)       : " << finalOther << " (" << pctFinalOther << "%)\n";
    std::cout << " - Non-Luma Blocks                     : " << finalNonLuma << " (" << pctFinalNonLuma << "%)\n";
    std::cout << " - Total Final Blocks Coded            : " << totalFinal << " (100.00%)\n";
    std::cout << "-------------------------------------------------------\n";
    std::cout << "Summary: " << pctTotalSkipped << "% of the blocks skipped the Intra search.\n";
    std::cout << "=======================================================\n";
}
} // namespace vvenc