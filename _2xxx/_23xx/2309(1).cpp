#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <numeric>
#include <utility>

constexpr int dwarf_cnt{9};
constexpr int real_sum{100};

using Dwarfs = std::array<int, dwarf_cnt>;

std::pair<int, int> find_fake_dwarfs(const Dwarfs& dwarfs)
{
    const int total_sum{std::accumulate(dwarfs.cbegin(), dwarfs.cend(), 0)};
    const int fake_sum{total_sum - real_sum};

    for (auto it1{dwarfs.cbegin()}; it1 != std::prev(dwarfs.cend()); ++it1) {
        for (auto it2{std::next(it1)}; it2 != dwarfs.cend(); ++it2) {
            if (*it1 + *it2 != fake_sum) {
                continue;
            }

            return {*it1, *it2};
        }
    }

    return {-1, -1};
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Dwarfs dwarfs{};
    for (auto& dwarf : dwarfs) {
        std::cin >> dwarf;
    }

    const auto [fake1, fake2]{find_fake_dwarfs(dwarfs)};

    std::sort(dwarfs.begin(), dwarfs.end());
    for (const auto& dwarf : dwarfs) {
        if (dwarf == fake1 || dwarf == fake2) {
            continue;
        }

        std::cout << dwarf << '\n';
    }

    return 0;
}
