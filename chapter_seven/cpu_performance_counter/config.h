#ifndef CONFIG_H
#define CONFIG_H

namespace config
{
    inline constexpr int recordInstruction{1};
    inline constexpr int recordCacheHit{2};
    inline constexpr int recordCacheMiss{3};
    inline constexpr int recordBranch{4};
    inline constexpr int recordMisprediction{5};
    inline constexpr int printStatistics{6};
    inline constexpr int resetStatistics{7};
    inline constexpr int exitProgram{8};
}

#endif