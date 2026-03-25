#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N{};
    int L{};
    std::cin >> N >> L;

    std::vector<int> poses(N);
    for (auto& pos : poses) {
        std::cin >> pos;
    }

    std::sort(poses.begin(), poses.end());

    int res{1};
    int last_pos{poses[0]};
    for (auto it{poses.cbegin() + 1}; it != poses.cend(); ++it) {
        const auto& pos{*it};

        if (pos - last_pos < L) {
            continue;
        }

        last_pos = pos;
        ++res;
    }

    std::cout << res << '\n';

    return 0;
}
