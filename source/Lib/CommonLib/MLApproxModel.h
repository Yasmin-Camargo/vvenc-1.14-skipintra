#pragma once

#include "CommonDef.h"
#include <atomic>

// 1 = Enable Early Skip via ML | 0 = Original VVenC (Baseline)
#define ML_SKIP_INTRA 1

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
};

} // namespace vvenc