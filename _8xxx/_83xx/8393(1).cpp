#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n{};
    std::cin >> n;

    int res{0};
    for (int i{1}; i <= n; ++i) {
        res += i;
    }

    std::cout << res << '\n';

    return 0;
}
