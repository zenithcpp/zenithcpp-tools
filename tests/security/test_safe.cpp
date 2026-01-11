#include "zenith/security/discipline.hpp"

ZENITH_ENFORCE_SECURITY(R"(
int factorial(int n) {
    return n <= 1 ? 1 : n * factorial(n - 1);
}
int main() { return factorial(10); }
)");

int main() { return 0; }
