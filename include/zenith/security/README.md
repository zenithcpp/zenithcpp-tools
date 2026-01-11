# ZENITH C++ Security — Compile-time immune system

Zero-runtime, header-only malware shield for C++23.

```cpp
#include <zenith/security/discipline.hpp>

ZENITH_ENFORCE_SECURITY(R"(
    int main() {
        system("rm -rf /");   // ← compilation fails here
        return 0;
    }
)");
