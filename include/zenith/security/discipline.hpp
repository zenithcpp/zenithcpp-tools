#pragma once

#include <zenith/constexpr_string_view.hpp>

namespace zenith::security {

constexpr bool contains_dangerous_call(constexpr_string_view source) {
    constexpr auto dangers = {
        "system(",
        "exec",
        "fork(",
        "popen(",
        "shell",
        "cmd",
        "process",
        "spawn"
    };

    for (auto danger : dangers) {
        if (source.find(danger) != constexpr_string_view::npos) {
            return true;
        }
    }

    return false;
}

template <constexpr_string_view source>
constexpr void enforce() {
    static_assert(!contains_dangerous_call(source),
                  "ZENITH SECURITY: Dangerous system call pattern detected — compilation blocked");
}

} // namespace zenith::security

#define ZENITH_ENFORCE_SECURITY(code) \
namespace { \
    constexpr auto _source = zenith::const_string<code>(); \
    constexpr void _zenith_check() { zenith::security::enforce<_source>(); } \
    constexpr auto _check = (_zenith_check(), true); \
}
