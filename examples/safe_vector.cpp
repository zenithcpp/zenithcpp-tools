#include "../include/constexpr_vector.hpp"

constexpr auto v = zenith::make_vector(1, 4, 9, 16);
static_assert(v.size() == 4);
static_assert(v.back() == 16);

int main() { return 0; }
