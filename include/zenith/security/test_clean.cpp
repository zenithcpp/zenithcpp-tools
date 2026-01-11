#include "include/zenith/security/discipline.hpp"
#include <iostream>

ZENITH_ENFORCE_SECURITY(R"(
    int factorial(int n) {
        return n <= 1 ? 1 : n * factorial(n - 1);
    }
    int main() { return factorial(5); }
)");
int main() {
    std::cout << "ZENITH SECURITY: Clean code — compilation succeeded\n";
}
