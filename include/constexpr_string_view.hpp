#pragma once
#include <cstddef>
#include <string_view>

namespace zenith {

template<std::size_t N>
struct const_string {
    constexpr const_string(const char (&str)[N]) {
        for (std::size_t i = 0; i < N; ++i) data[i] = str[i];
    }
    char data[N]{};
    [[nodiscard]] constexpr operator std::string_view() const { return {data, N-1}; }
    [[nodiscard]] constexpr std::string_view view() const { return *this; }
    [[nodiscard]] constexpr std::size_t size() const { return N-1; }
    [[nodiscard]] constexpr const char* begin() const { return data; }
    [[nodiscard]] constexpr const char* end() const { return data + N - 1; }
};

template<const_string Str>
[[nodiscard]] constexpr auto operator"" _cs() { return Str; }

} // namespace zenith
