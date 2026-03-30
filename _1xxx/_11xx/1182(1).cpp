#include <iostream>
#include <iterator>
#include <vector>

using Sequence = std::vector<int>;
using Sequence_it = Sequence::const_iterator;

void search(Sequence_it it, Sequence_it end, int target_sum, int cur_sum,
            int& res)
{
    if (it == end) {
        return;
    }

    if (cur_sum + *it == target_sum) {
        ++res;
    }

    search(std::next(it), end, target_sum, cur_sum, res);
    search(std::next(it), end, target_sum, cur_sum + *it, res);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N{};
    int S{};
    std::cin >> N >> S;

    Sequence sequence(N);
    for (auto& element : sequence) {
        std::cin >> element;
    }

    int res{0};

    search(sequence.cbegin(), sequence.cend(), S, 0, res);

    std::cout << res << '\n';

    return 0;
}
