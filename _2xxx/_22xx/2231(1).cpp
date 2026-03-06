#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N{};
    std::cin >> N;

    int res{0};
    for (int i{1}; i <= N; ++i) {
        int digit_sum{0};
        for (int temp{i}; temp > 0; temp /= 10) {
            digit_sum += temp % 10;
        }

        if (i + digit_sum == N) {
            res = i;
            break;
        }
    }

    std::cout << res << '\n';

    return 0;
}
