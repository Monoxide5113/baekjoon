#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N{};
    int X{};
    std::cin >> N >> X;

    std::vector<int> A(N);
    for (auto& a : A) {
        std::cin >> a;
    }

    for (const auto& a : A) {
        if (a < X) {
            std::cout << a << ' ';
        }
    }
    std::cout << '\n';

    return 0;
}
