#include <algorithm>
#include <bitset>
#include <iostream>
#include <utility>
#include <vector>

constexpr int max_day{1'001};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N{};
    std::cin >> N;

    std::vector<std::pair<int, int>> tasks(N);
    for (auto& [d, w] : tasks) {
        std::cin >> d >> w;
    }

    std::sort(tasks.begin(), tasks.end(), [](auto a, auto b) {
        if (a.second != b.second) {
            return a.second > b.second;
        }

        return a.first > b.first;
    });

    int res{0};
    std::bitset<max_day> days;
    for (const auto& [d, w] : tasks) {
        for (int i{d}; i >= 1; --i) {
            if (days[i]) {
                continue;
            }

            days.set(i);
            res += w;
            break;
        }
    }

    std::cout << res << '\n';

    return 0;
}
