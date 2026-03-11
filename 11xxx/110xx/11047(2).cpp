#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N{};
    int K{};
    std::cin >> N >> K;

    std::vector<int> coins(N);
    for (auto& c : coins) {
        std::cin >> c;
    }

    std::reverse(coins.begin(), coins.end());

    int res{0};
    int remain_amount{K};
    for (const auto& c : coins) {
        if (remain_amount == 0) {
            break;
        }

        res += remain_amount / c;
        remain_amount %= c;
    }

    std::cout << res << '\n';

    return 0;
}
