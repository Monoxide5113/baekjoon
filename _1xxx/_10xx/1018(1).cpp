#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

constexpr char white{'W'};
constexpr char black{'B'};

char get_valid_color(int row, int col)
{
    if ((row + col) % 2 == 0) {
        return white;
    }

    return black;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N{};
    int M{};
    std::cin >> N >> M;

    std::vector<std::string> board(N);
    for (auto& line : board) {
        std::cin >> line;
    }

    int res{8 * 8};

    for (int i{0}; i <= N - 8; ++i) {
        for (int j{0}; j <= M - 8; ++j) {
            int cnt{0};

            for (int k{0}; k < 8; ++k) {
                for (int l{0}; l < 8; ++l) {
                    const auto color{get_valid_color(k, l)};

                    if (board[i + k][j + l] != color) {
                        continue;
                    }

                    ++cnt;
                }
            }

            res = std::min({res, cnt, (8 * 8) - cnt});
        }
    }

    std::cout << res << '\n';

    return 0;
}
