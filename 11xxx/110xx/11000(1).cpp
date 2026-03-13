#include <algorithm>
#include <iostream>
#include <queue>
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

    std::sort(meetings.begin(), meetings.end());

    std::priority_queue<int, std::vector<int>, std::greater<>> min_heap;
    min_heap.push(meetings[0].second);
    for (auto it{meetings.cbegin() + 1}; it != meetings.cend(); ++it) {
        const auto& [start, end]{*it};

        if (min_heap.top() <= start) {
            min_heap.pop();
        }

        min_heap.push(end);
    }

    const int res{static_cast<int>(min_heap.size())};

    std::cout << res << '\n';

    return 0;
}
