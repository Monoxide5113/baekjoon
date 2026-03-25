#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

constexpr int problem_cnt{11};
constexpr int penalty{20};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<std::pair<int, int>> problems(problem_cnt);
    for (auto& [D, V] : problems) {
        std::cin >> D >> V;
    }

    std::sort(problems.begin(), problems.end());

    int res{0};
    int acc_time{0};
    for (const auto& [D, V] : problems) {
        acc_time += D;
        res += acc_time + penalty * V;
    }

    std::cout << res << '\n';

    return 0;
}
