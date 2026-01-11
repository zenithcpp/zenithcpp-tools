#include "include/zenith/security/discipline.hpp"
#include <iostream>

ZENITH_ENFORCE_SECURITY(R"(
    int main() { return 0; }
)");

int main() {
    std::cout << "ZENITH SECURITY — Autonomous shield active\n";
}
