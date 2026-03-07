#include <algorithm>
#include <iostream>

int get_digit_cnt(int num)
{
    int ret{0};

    for (int tmp{num}; tmp > 0; tmp /= 10) {
        ++ret;
    }

    return ret;
}

int get_digit_sum(int num)
{
    int ret{0};

    for (int tmp{num}; tmp > 0; tmp /= 10) {
        ret += tmp % 10;
    }

    return ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N{};
    std::cin >> N;

    int res{0};
    for (int i{std::max(1, N - (get_digit_cnt(N) * 9))}; i <= N; ++i) {
        if (i + get_digit_sum(i) != N) {
            continue;
        }

        res = i;
        break;
    }

    std::cout << res << '\n';

    return 0;
}
