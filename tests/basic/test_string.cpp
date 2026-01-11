#include "include/zenith/constexpr_string_view.hpp"
#include <iostream>

constexpr auto s = "ZENITH"_cs;
static_assert(s.size() == 6);

int main() {
    std::cout << "constexpr_string_view works — size = " << s.size() << "\n";
}
