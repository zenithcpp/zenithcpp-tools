#include "../include/constexpr_vector.hpp"

constexpr bool test_overflow() {
    constexpr auto v = zenith::make_vector(1, 2, 3); // capacity 3
    constexpr auto v2 = v;
    v2.push_back(4); // should trigger static_assert — overflow
    return true;
}

static_assert(test_overflow()); // force compile-time evaluation

int main() { return 0; }
