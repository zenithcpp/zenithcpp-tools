#pragma once

#include <array>
#include <cstddef>

namespace zenith {

template <typename T, std::size_t Capacity>
struct constexpr_vector {
    std::array<T, Capacity> data;
    std::size_t size_ = 0;

    constexpr void push_back(const T& value) {
        static_assert(size_ < Capacity, "ZENITH CONSTEXPR_VECTOR: overflow — capacity exceeded at compile time");
        data[size_++] = value;
    }

    constexpr std::size_t size() const { return size_; }
    constexpr const T& operator[](std::size_t i) const { return data[i]; }
    constexpr const T& back() const { return data[size_ - 1]; }
};

template <typename... Ts>
constexpr auto make_vector(Ts&&... values) {
    constexpr std::size_t N = sizeof...(Ts);
    constexpr_vector<std::common_type_t<Ts...>, N> vec{};
    std::size_t i = 0;
    ((vec.data[i++] = values), ...);
    vec.size_ = N;
    return vec;
}

} // namespace zenith
