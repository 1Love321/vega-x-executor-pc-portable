#include "../include/vega_x_executor_pc_portable_runtime.hpp"
#include <windows.h>
#include <atomic>

namespace vega_x_executor_pc_portable {
static std::atomic<bool> g_running{true};
void PollHotkeys(bool& menu_open) noexcept {
    if (GetAsyncKeyState(VK_INSERT) & 1) menu_open = !menu_open;
    if (GetAsyncKeyState(VK_END) & 1) g_running.store(false, std::memory_order_relaxed);
}
} // namespace vega_x_executor_pc_portable

int main() {
    bool menu_open = true;
    while (vega_x_executor_pc_portable::g_running.load(std::memory_order_relaxed)) {
        vega_x_executor_pc_portable::PollHotkeys(menu_open);
        Sleep(6);
    }
    return 0;
}
