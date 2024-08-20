#pragma once

#include <algorithm>
#include <iostream>
#include <memory>
#include <unordered_set>
#include <vector>
#include "node.hh"
#include "node.cc"


int main() {
  std::vector<std::shared_ptr<Node>> nodes;
  populate_nodes_randomly(nodes, 23, 8);

  for(auto n: nodes){
    std::cout << n.use_count() << " refs ->\t" << *n << "\n";

  }
  return 0;
}