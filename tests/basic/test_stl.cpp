#include <iostream>
#include "include/zenith/stl/map.hpp"
#include "include/zenith/stl/unordered_map.hpp"
#include "include/zenith/stl/deque.hpp"
#include "include/zenith/stl/list.hpp"

constexpr auto test_map() {
    zenith::stl::map<int, std::string> m;
    m.insert({1, "one"});
    m.insert({2, "two"});
    m.insert({3, "three"});
    return m;
}

constexpr auto test_unordered_map() {
    zenith::stl::unordered_map<int, std::string> um;
    um.insert({4, "four"});
    um.insert({5, "five"});
    return um;
}

constexpr auto test_deque() {
    zenith::stl::deque<int> d;
    d.push_front(0);
    d.push_back(6);
    d.push_front(-1);
    return d;
}

constexpr auto test_list() {
    zenith::stl::list<int> l;
    l.push_front(7);
    l.push_back(8);
    l.push_front(9);
    return l;
}

int main() {
    constexpr auto m = test_map();
    constexpr auto um = test_unordered_map();
    constexpr auto d = test_deque();
    constexpr auto l = test_list();

    std::cout << "map size: " << m.size() << std::endl;
    std::cout << "unordered_map size: " << um.size() << std::endl;
    std::cout << "deque size: " << d.size() << std::endl;
    std::cout << "list size: " << l.size() << std::endl;
    return 0;
}
