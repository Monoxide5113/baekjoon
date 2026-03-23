#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using Board = std::vector<std::string>;

int get_max_candy(const Board& board, int row_start, int row_end, int col_start,
                  int col_end)
{
    int ret{1};

    const int N{static_cast<int>(board.size())};
    for (int i{row_start}; i <= row_end; ++i) {
        int row_cnt{1};

        for (int j{0}; j < N - 1; ++j) {
            if (board[i][j] != board[i][j + 1]) {
                row_cnt = 1;
                continue;
            }

            ++row_cnt;
            ret = std::max(ret, row_cnt);
        }
    }

    for (int i{col_start}; i <= col_end; ++i) {
        int col_cnt{1};

        for (int j{0}; j < N - 1; ++j) {
            if (board[j][i] != board[j + 1][i]) {
                col_cnt = 1;
                continue;
            }

            ++col_cnt;
            ret = std::max(ret, col_cnt);
        }
    }

    return ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N{};
    std::cin >> N;

    Board board(N);
    for (auto& line : board) {
        std::cin >> line;
    }

    int res{get_max_candy(board, 0, N - 1, 0, N - 1)};

    for (int i{0}; i < N; ++i) {
        for (int j{0}; j < N - 1; ++j) {
            if (board[i][j] == board[i][j + 1]) {
                continue;
            }

            std::swap(board[i][j], board[i][j + 1]);
            res = std::max(res, get_max_candy(board, i, i, j, j + 1));
            std::swap(board[i][j], board[i][j + 1]);
        }
    }

    for (int i{0}; i < N; ++i) {
        for (int j{0}; j < N - 1; ++j) {
            if (board[j][i] == board[j + 1][i]) {
                continue;
            }

            std::swap(board[j][i], board[j + 1][i]);
            res = std::max(res, get_max_candy(board, j, j + 1, i, i));
            std::swap(board[j][i], board[j + 1][i]);
        }
    }

    std::cout << res << '\n';

    return 0;
}
