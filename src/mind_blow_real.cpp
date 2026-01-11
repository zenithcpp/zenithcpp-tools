#include "include/zenith/constexpr_vector.hpp"
#include <iostream>

constexpr auto v = []{
    zenith::constexpr_vector<int, 2000> vec;
    for (int i = 0; i < 1000; ++i)
        vec.push_back(i * i);
    return vec;
}();

static_assert(v.size() == 1000);
static_assert(v[999] == 999*999);

int main() {
    std::cout << "ZENITH C++ — constexpr_vector verification\n";
    std::cout << "Elements constructed at compile time : 1000\n";
    std::cout << "Last element (999²)                  : " << v[999] << "\n";
}
