#pragma once
#include <zenith/stl/vector.hpp>
#include <string_view>

namespace zenith::stl {

class string : public vector<char> {
public vector<char> {
public:
    using vector<char>::vector;

    constexpr string() = default;
    constexpr string(const char* s) {
        while (*s) push_back(*s++);
    }

    [[nodiscard]] constexpr std::string_view view() const {
        return {data(), size()};
    }

    [[nodiscard]] constexpr const char* c_str() const {
        push_back('\0');
        pop_back();
        return data();
    }

    constexpr string& operator+=(const char* s) {
        while (*s) push_back(*s++);
        return *this;
    }
};

} // namespace zenith::stl
