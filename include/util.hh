#pragma once

#include <cstdlib>
#include <functional>
#include <utility>

std::pair<int, int>
generate_random_pair(int n);

template<typename T, typename V>
struct PairHash {
  size_t operator()(const std::pair<T, V>& p) const {
    return std::hash<T>()(p.first) ^ (std::hash<V>()(p.second) >> 1);
  }
};
