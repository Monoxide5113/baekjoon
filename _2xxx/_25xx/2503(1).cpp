#include <bitset>
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::bitset<999 + 1> ans;

    for (int i{100}; i <= 999; ++i) {
        const auto i_digits{std::to_string(i)};

        if (i_digits[1] == '0' || i_digits[2] == '0') {
            continue;
        }
        if (i_digits[0] == i_digits[1] || i_digits[1] == i_digits[2]
            || i_digits[2] == i_digits[0]) {
            continue;
        }

        ans.set(i);
    }

    int N{};
    std::cin >> N;

    for (int n{0}; n < N; ++n) {
        int num{};
        int num_strike{};
        int num_ball{};
        std::cin >> num >> num_strike >> num_ball;

        const auto num_digits{std::to_string(num)};

        for (int i{100}; i <= 999; ++i) {
            if (!ans[i]) {
                continue;
            }

            int i_strike{0};
            int i_ball{0};

            const auto i_digits{std::to_string(i)};

            for (int j{0}; j < 3; ++j) {
                if (num_digits[j] == i_digits[j]) {
                    ++i_strike;
                    continue;
                }

                if (i_digits.find(num_digits[j]) != std::string::npos) {
                    ++i_ball;
                }
            }

            if (num_strike == i_strike && num_ball == i_ball) {
                continue;
            }

            ans.reset(i);
        }
    }

    const int res{static_cast<int>(ans.count())};

    std::cout << res << '\n';

    return 0;
}
