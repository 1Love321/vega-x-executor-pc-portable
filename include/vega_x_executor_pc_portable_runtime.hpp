#pragma once
#include <cstdint>

namespace vega_x_executor_pc_portable {
inline constexpr const char* kModuleName = "vega-x-executor-pc-portable";
inline constexpr const char* kBuildSalt = "14fef328d46487e8";
struct RuntimeConfig {
    uint32_t target_fps = 144;
    float fov_radius = 65.0f;
    float smooth_factor = 1.45f;
    bool draw_bounds = true;
};
} // namespace vega_x_executor_pc_portable
