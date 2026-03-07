#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N{};
    int X{};
    std::cin >> N >> X;

    for (int i{0}; i < N; ++i) {
        int a{};
        std::cin >> a;

        if (a >= X) {
            continue;
        }

        std::cout << a << ' ';
    }
    std::cout << '\n';

    return 0;
}
