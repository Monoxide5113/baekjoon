#include <bitset>
#include <iostream>
#include <vector>

constexpr int max_tri{1'000};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> tris;

    int tri{0};
    for (int i{1};; ++i) {
        tri += i;
        if (tri > max_tri) {
            break;
        }
        tris.push_back(tri);
    }

    std::bitset<max_tri + 1> nums;

    const int tri_cnt{static_cast<int>(tris.size())};
    for (int i{0}; i < tri_cnt; ++i) {
        const int tmp_num1{tris[i] + tris[i] + tris[i]};
        if (tmp_num1 > max_tri) {
            break;
        }

        for (int j{i}; j < tri_cnt; ++j) {
            const int tmp_num2{tris[i] + tris[j] + tris[j]};
            if (tmp_num2 > max_tri) {
                break;
            }

            for (int k{j}; k < tri_cnt; ++k) {
                const int num{tris[i] + tris[j] + tris[k]};
                if (num > max_tri) {
                    break;
                }
                nums.set(num);
            }
        }
    }

    int T{};
    std::cin >> T;

    for (int t{0}; t < T; ++t) {
        int K{};
        std::cin >> K;

        std::cout << nums[K] << '\n';
    }

    return 0;
}
