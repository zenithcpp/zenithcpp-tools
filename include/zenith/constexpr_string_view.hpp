#pragma once
#include <cstddef>
#include <string_view>

namespace zenith {

template<std::size_t N>
struct const_string {
    char data[N]{};

    consteval const_string(const char (&str)[N]) {
        for (std::size_t i = 0; i < N; ++i) data[i] = str[i];
    }

    [[nodiscard]] consteval std::string_view view() const { return {data, N-1}; }
    [[nodiscard]] consteval std::size_t size() const { return N-1; }
};

} // namespace zenith

// Global type alias for visibility in templates
template<std::size_t N>
using constexpr_string_view = zenith::const_string<N>;
