#include <zenith/constexpr_vector.hpp>
#include <iostream>

constexpr bool test() {
    zenith::constexpr_vector<int, 2000> v;
    for (int i = 0; i < 1000; ++i)
        v.push_back(i * i);
    for (int i = 0; i < 1000; ++i)
        if (v[i] != i * i)
            return false;
    return v.size() == 1000;
}
static_assert(test());

int main() {
    std::cout << "ZENITH C++ — Gift #2: 1000 push_backs at compile time — SUCCESS\n";
}
