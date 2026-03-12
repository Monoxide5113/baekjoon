#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N{};
    std::cin >> N;

    std::vector<std::pair<int, int>> meetings(N);
    for (auto& [start, end] : meetings) {
        std::cin >> start >> end;
    }

    std::sort(meetings.begin(), meetings.end(), [](auto a, auto b) {
        if (a.second != b.second) {
            return a.second < b.second;
        }

        return a.first < b.first;
    });

    int res{1};
    int last_end{meetings[0].second};
    for (auto it{meetings.cbegin() + 1}; it != meetings.cend(); ++it) {
        const auto& [start, end]{*it};

        if (start < last_end) {
            continue;
        }

        last_end = end;
        ++res;
    }

    std::cout << res << '\n';

    return 0;
}
