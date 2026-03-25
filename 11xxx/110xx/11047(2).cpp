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
    for (auto& coin : coins) {
        std::cin >> coin;
    }

    std::reverse(coins.begin(), coins.end());

    int res{0};
    int remain_amount{K};
    for (const auto& coin : coins) {
        if (remain_amount == 0) {
            break;
        }

        res += remain_amount / coin;
        remain_amount %= coin;
    }

    std::cout << res << '\n';

    return 0;
}
