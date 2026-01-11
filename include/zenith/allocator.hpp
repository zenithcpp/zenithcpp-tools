#pragma once
#include <cstddef>
#include <new>
#include <limits>

namespace zenith::stl {

template<typename T>
struct allocator {
    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;

    constexpr allocator() noexcept = default;
    template<typename U>
    constexpr allocator(const allocator<U>&) noexcept {}

    [[nodiscard]] constexpr T* allocate(std::size_t n) {
        if (n > std::numeric_limits<std::size_t>::max() / sizeof(T))
            throw std::bad_alloc();
        return static_cast<T*>(::operator new[](n * sizeof(T)));
    }

    constexpr void deallocate(T* p, std::size_t) noexcept {
        ::operator delete<a href="p" target="_blank" rel="noopener noreferrer nofollow"></a>;
    }

    template<typename U>
    constexpr bool operator==(const allocator<U>&) const noexcept { return true; }
};

} // namespace zenith::stl
