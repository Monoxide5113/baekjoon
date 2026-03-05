#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <utility>

constexpr int dwarf_cnt{9};
constexpr int real_sum{100};

std::pair<int, int> find_fake_dwarfs(const std::array<int, dwarf_cnt>& dwarfs)
{
    const int total_sum{std::accumulate(dwarfs.cbegin(), dwarfs.cend(), 0)};
    const int fake_sum{total_sum - real_sum};

    for (int i{0}; i < dwarf_cnt - 1; ++i) {
        for (int j{i + 1}; j < dwarf_cnt; ++j) {
            if (dwarfs[i] + dwarfs[j] == fake_sum) {
                return {dwarfs[i], dwarfs[j]};
            }
        }
    }
    return {-1, -1};
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::array<int, dwarf_cnt> dwarfs{};
    for (auto& dwarf : dwarfs) {
        std::cin >> dwarf;
    }

    const auto [fake1, fake2]{find_fake_dwarfs(dwarfs)};

    std::sort(dwarfs.begin(), dwarfs.end());
    for (const auto& dwarf : dwarfs) {
        if (dwarf != fake1 && dwarf != fake2) {
            std::cout << dwarf << '\n';
        }
    }

    return 0;
}
