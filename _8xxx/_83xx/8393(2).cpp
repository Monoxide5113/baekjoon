#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n{};
    std::cin >> n;

    const int res{(n * (n + 1)) / 2};

    std::cout << res << '\n';

    return 0;
}
