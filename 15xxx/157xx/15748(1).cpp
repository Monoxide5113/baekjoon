#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int L{};
    int N{};
    int r_F{};
    int r_B{};
    std::cin >> L >> N >> r_F >> r_B;

    std::vector<std::pair<int, int>> rest_stops(N);
    for (auto& [x, c] : rest_stops) {
        std::cin >> x >> c;
    }

    std::sort(rest_stops.begin(), rest_stops.end(), std::greater<>());

    long long res{0};
    int last_rest_stop{0};
    const long long diff{r_F - r_B};
    for (const auto [c, x] : rest_stops) {
        if (x <= last_rest_stop) {
            continue;
        }

        const long long dist{x - last_rest_stop};
        res += dist * diff * c;
        last_rest_stop = x;
    }

    std::cout << res << '\n';

    return 0;
}
