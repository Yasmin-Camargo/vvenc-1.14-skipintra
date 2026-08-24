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

public:
    static bool evaluateSkipIntra( const CodingStructure& cs, const CodingUnit& cu, double interCost );
    static void incrementTotalEval() { countTotalEval++; }

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

    static void addTimeIntraSearch(long long timeUs) { countTimeIntraSearchUs += timeUs; }
};

} // namespace vvenc