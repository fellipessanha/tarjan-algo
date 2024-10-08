#include <algorithm>
#include <iostream>
#include <memory>
#include <unordered_set>
#include <vector>

#include "graph.hh"
#include "node.hh"
#include "tarjan.hh"

void
output_edges(std::vector<std::shared_ptr<Node>>& nodes) {
  for (auto [a, b] : draw_edges(nodes)) {
    std::cout << a->m_val << " " << b->m_val << "\n";
  }
}
void
output_nodes(std::vector<std::shared_ptr<Node>>& nodes) {
  for (auto n : (nodes)) {
    std::cout << n.use_count() << " refs ->\t" << *n << "\n";
  }
}

int
main(int argc, char* argv[]) {
  int node_count = argc >= 2 ? std::stoi(argv[1]) : 10;
  int edge_count = argc == 3 ? std::stoi(argv[2]) : 6;
  auto nodes = populate_nodes_randomly(node_count, edge_count);

  output_edges(nodes);
  output_nodes(nodes);

  auto tarj = find_strongly_connected_components(nodes);
  std::cout << "tarjan output:\n";
  for (auto [n, i] : tarj) {
    std::cout << n->m_val << " " << i << std::endl;
  }

  return 0;
}
