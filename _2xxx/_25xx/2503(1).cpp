#include <array>
#include <bitset>
#include <iostream>

constexpr int min_num{100};
constexpr int max_num{999};

constexpr int digit{3};

std::array<int, digit> get_digits(int num)
{
    std::array<int, digit> ret{};

    ret[0] = num / 100;
    ret[1] = (num / 10) % 10;
    ret[2] = num % 10;

    return ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::bitset<max_num + 1> ans;

    for (int i{min_num}; i <= max_num; ++i) {
        const auto i_digits{get_digits(i)};

        if (i_digits[1] == 0 || i_digits[2] == 0) {
            continue;
        }
        if (i_digits[0] == i_digits[1] || i_digits[1] == i_digits[2]
            || i_digits[2] == i_digits[0]) {
            continue;
        }

        ans.set(i, true);
    }

    int N{};
    std::cin >> N;

    for (int n{0}; n < N; ++n) {
        int num{};
        int num_strike{};
        int num_ball{};
        std::cin >> num >> num_strike >> num_ball;

        const auto num_digits{get_digits(num)};

        for (int i{min_num}; i <= max_num; ++i) {
            if (!ans[i]) {
                continue;
            }

            int i_strike{0};
            int i_ball{0};

            const auto i_digits{get_digits(i)};

            for (int j{0}; j < digit; ++j) {
                for (int k{0}; k < digit; ++k) {
                    if (num_digits[j] != i_digits[k]) {
                        continue;
                    }

                    if (j == k) {
                        ++i_strike;
                    }
                    else {
                        ++i_ball;
                    }
                }
            }

            if (num_strike == i_strike && num_ball == i_ball) {
                continue;
            }

            ans.reset(i);
        }
    }

    const int res{ans.count()};
    std::cout << res << '\n';

    return 0;
}
