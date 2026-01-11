#include "include/zenith/security/discipline.hpp"
ZENITH_ENFORCE_SECURITY(R"(
    int main() { system("rm -rf /"); return 0; }
)");
int main() { return 0; }
