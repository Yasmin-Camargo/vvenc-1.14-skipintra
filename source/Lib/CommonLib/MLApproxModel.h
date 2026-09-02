#pragma once

#include "CommonDef.h"
#include <atomic>
#include <string>
#include <cstdlib>

namespace vvenc {

class CodingStructure;
class CodingUnit;

class MLApproxModel {
private:
    static std::atomic<long long> countTotalEval;
    static std::atomic<long long> countIsSplit;
    static std::atomic<long long> countNotIntraKept;
    static std::atomic<long long> countLossless;
    static std::atomic<long long> countTimeIntraSearchUs;

    static std::atomic<long long> globalTotalBlocksEvaluated;
    static std::atomic<long long> totalIntraBlocksEvaluated;
    static std::atomic<long long> intraLumaEvaluated;
    static std::atomic<long long> intraChromaEvaluated;
    static std::atomic<long long> intraLumaAtFrameLevel0;

    static std::atomic<long long> finalIntraKept;
    static std::atomic<long long> finalSplit;
    static std::atomic<long long> finalOther;
    static std::atomic<long long> finalNonLuma;

public:
    static bool evaluateSkipIntra( const CodingStructure& cs, const CodingUnit& cu, double interCost );
    static void incrementTotalEval() { countTotalEval++; }

    static void incrementGlobalTotalBlocks() { globalTotalBlocksEvaluated++; }
    static void incrementIntraBlocks(bool isLumaBlock, bool isFrameLevel0);

    static void incrementFinalIntraKept() { finalIntraKept++; }
    static void incrementFinalSplit() { finalSplit++; }
    static void incrementFinalOther() { finalOther++; }
    static void incrementFinalNonLuma() { finalNonLuma++; }

    static void printSummary();

    static inline bool isSkipEnabled() {
        if (const char* env_p = std::getenv("ML_SKIP_INTRA")) {
            return std::string(env_p) == "1";
        }
        return true;
    }

    static inline bool isIsSplitEnabled() {
        if (const char* env_p = std::getenv("ML_ENABLE_ISSPLIT")) {
            return std::string(env_p) == "1";
        }
        return true;
    }

    static inline bool isIntraKeptEnabled() {
        if (const char* env_p = std::getenv("ML_ENABLE_INTRAKEPT")) {
            return std::string(env_p) == "1";
        }
        return true;
    }

    static inline bool isSkipAllIntraEnabled() {
        if (const char* env_p = std::getenv("ML_SKIP_ALL_INTRA")) {
            return std::string(env_p) == "1";
        }
        return false;
    }

    static void addTimeIntraSearch(long long timeUs) { countTimeIntraSearchUs += timeUs; }
};

} // namespace vvenc