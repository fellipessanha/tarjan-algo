#include <algorithm>
#include <iostream>
#include <memory>
#include <unordered_set>
#include <vector>

#include "graph.hh"
#include "node.hh"

void output_edges(std::vector<std::shared_ptr<Node>> &nodes) {
  for (auto [a, b] : draw_edges(nodes)) {
    std::cout << a->m_val << " " << b->m_val << "\n";
  }
}
void output_nodes(std::vector<std::shared_ptr<Node>> &nodes) {
  for (auto n : (nodes)) {
    std::cout << n.use_count() << " refs ->\t" << *n << "\n";
  }
}

int main() {
  auto nodes = populate_nodes_randomly(23, 30);

  output_edges(nodes);
  output_nodes(nodes);

  return 0;
}
