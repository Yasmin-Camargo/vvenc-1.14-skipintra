#pragma once

#include "CommonDef.h"
#include <atomic>

namespace vvenc {

class CodingStructure;
class CodingUnit;

class MLApproxModel {
private:
    static std::atomic<long long> countTotalEval;
    static std::atomic<long long> countIsSplit;
    static std::atomic<long long> countNotIntraKept;
    static std::atomic<long long> countLossless;

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
};

} // namespace vvenc