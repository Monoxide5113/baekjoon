#include <algorithm>
#include <iostream>
#include <vector>

constexpr int empty_slot{0};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N{};
    int K{};
    std::cin >> N >> K;

    std::vector<int> device_schedule(K);
    for (auto& device : device_schedule) {
        std::cin >> device;
    }

    std::vector<int> multitap(N, empty_slot);

    int res{0};
    for (auto it1{device_schedule.cbegin()}; it1 != device_schedule.cend();
         ++it1) {
        if (std::find(multitap.cbegin(), multitap.cend(), *it1)
            != multitap.cend()) {
            continue;
        }

        if (auto empty_it{
                std::find(multitap.begin(), multitap.end(), empty_slot)};
            empty_it != multitap.end()) {
            *empty_it = *it1;
            continue;
        }

        auto target_it{multitap.begin()};
        auto farthest_use_it{it1};
        for (auto it2{multitap.begin()}; it2 != multitap.end(); ++it2) {
            const auto next_use_it{
                std::find(it1 + 1, device_schedule.cend(), *it2)};

            if (next_use_it == device_schedule.cend()) {
                target_it = it2;
                break;
            }

            if (next_use_it > farthest_use_it) {
                farthest_use_it = next_use_it;
                target_it = it2;
            }
        }

        *target_it = *it1;
        ++res;
    }

    std::cout << res << '\n';

    return 0;
}
