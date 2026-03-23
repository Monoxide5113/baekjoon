#include <bitset>
#include <iostream>
#include <vector>

constexpr int max_tri{1'000};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> tris;

    for (int i{1};; ++i) {
        const int tri{(i * (i + 1)) / 2};

        if (tri > max_tri) {
            break;
        }

        tris.push_back(tri);
    }

    std::bitset<max_tri + 1> nums;

    for (auto it1{tris.cbegin()}; it1 != tris.cend(); ++it1) {
        if (*it1 + *it1 + *it1 > max_tri) {
            break;
        }

        for (auto it2{it1}; it2 != tris.cend(); ++it2) {
            if (*it1 + *it2 + *it2 > max_tri) {
                break;
            }

            for (auto it3{it2}; it3 != tris.cend(); ++it3) {
                const int num{*it1 + *it2 + *it3};

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
