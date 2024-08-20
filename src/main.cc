#include <algorithm>
#include <iostream>
#include <memory>
#include <unordered_set>
#include <vector>
#include "node.hh"
#include "node.cc"


int main() {
  auto nodes = populate_nodes_randomly(23, 30);

  for(auto n: nodes){
    std::cout << n.use_count() << " refs ->\t" << *n << "\n";
  }
  return 0;
}
