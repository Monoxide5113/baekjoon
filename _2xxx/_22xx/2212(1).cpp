#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N{};
    int K{};
    std::cin >> N >> K;

    std::vector<int> sensors(N);
    for (auto& sensor : sensors) {
        std::cin >> sensor;
    }

    std::sort(sensors.begin(), sensors.end());

    std::vector<int> diffs(N - 1);
    for (int i{0}; i < N - 1; ++i) {
        diffs[i] = sensors[i + 1] - sensors[i];
    }

    std::sort(diffs.begin(), diffs.end());

    const int gaps{std::max(0, N - K)};
    const int res{std::accumulate(diffs.begin(), diffs.begin() + gaps, 0)};

    std::cout << res << '\n';

    return 0;
}
