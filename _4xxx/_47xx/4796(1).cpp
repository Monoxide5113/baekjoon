#include <algorithm>
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int t{1};; ++t) {
        int L{};
        int P{};
        int V{};
        std::cin >> L >> P >> V;

        if (L == 0 && P == 0 && V == 0) {
            break;
        }

        const int res{(V / P) * L + std::min(V % P, L)};

        std::cout << "Case " << t << ": " << res << '\n';
    }

    return 0;
}
