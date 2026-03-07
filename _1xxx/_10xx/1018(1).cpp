#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

constexpr char white{'W'};
constexpr char black{'B'};

constexpr int len{8};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N{};
    int M{};
    std::cin >> N >> M;

    std::vector<std::string> board(N);
    for (auto& s : board) {
        std::cin >> s;
    }

    int res{len * len};

    for (int i{0}; i <= N - len; ++i) {
        for (int j{0}; j <= M - len; ++j) {
            int cnt{0};

            for (int k{0}; k < len; ++k) {
                for (int l{0}; l < len; ++l) {
                    if ((k + l) % 2 == 0 && board[i + k][j + l] != white) {
                        continue;
                    }
                    if ((k + l) % 2 != 0 && board[i + k][j + l] != black) {
                        continue;
                    }

                    ++cnt;
                }
            }

            res = std::min({res, cnt, (len * len) - cnt});
        }
    }

    std::cout << res << '\n';

    return 0;
}
