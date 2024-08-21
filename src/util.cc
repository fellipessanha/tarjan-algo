#include "util.hh"

#include <cstddef>
#include <cstdlib>
#include <functional>
#include <utility>

std::pair<int, int>
generate_random_pair(int n) {
  int a = rand() % n, b = rand() % (n - 1);
  if (a == b) {
    return { a, n - 1 };
  }
  return { a, b };
}
