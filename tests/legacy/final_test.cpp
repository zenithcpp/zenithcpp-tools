#include "include/zenith/constexpr_string_view.hpp"
#include "include/zenith/constexpr_vector.hpp"
#include "include/zenith/security/discipline.hpp"
#include <iostream>

constexpr auto s = "ZENITH"_cs;
static_assert(s.size() == 6);

constexpr auto v = []{
    zenith::constexpr_vector<int, 2000> vec;
    for (int i = 0; i < 1000; ++i) vec.push_back(i * i);
    return vec;
}();
static_assert(v.size() == 1000);
static_assert(v[999] == 999*999);

ZENITH_ENFORCE_SECURITY(R"(
    int main() { system("rm -rf /"); return 0; }
)");

int main() {
    std::cout << "ZENITH C++ Tools v1 — ALL THREE GIFTS VERIFIED\n";
    std::cout << "constexpr_string_view : " << s.size() << "\n";
    std::cout << "constexpr_vector      : " << v.size() << " elements\n";
    std::cout << "security shield       : active\n";
}
