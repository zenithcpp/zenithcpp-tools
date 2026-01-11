#pragma once
#include <array>
#include <cstddef>

namespace zenith {

template<typename T, std::size_t Capacity>
struct constexpr_vector {
    std::array<T, Capacity> storage{};
    std::size_t size_ = 0;

    constexpr constexpr_vector() = default;

    constexpr void push_back(const T& value) {
        storage[size_++] = value;
    }

    constexpr void push_back(T&& value) {
        storage[size_++] = std::move(value);
    }

    [[nodiscard]] constexpr std::size_t size() const { return size_; }
    [[nodiscard]] constexpr std::size_t capacity() const { return Capacity; }
    [[nodiscard]] constexpr bool empty() const { return size_ == 0; }

    [[nodiscard]] constexpr T& operator[](std::size_t i) { return storage[i]; }
    [[nodiscard]] constexpr const T& operator[](std::size_t i) const { return storage[i]; }

    [[nodiscard]] constexpr T* begin() { return storage.data(); }
    [[nodiscard]] constexpr T* end() { return storage.data() + size_; }
    [[nodiscard]] constexpr const T* begin() const { return storage.data(); }
    [[nodiscard]] constexpr const T* end() const { return storage.data() + size_; }
};

} // namespace zenith
