#include "graph.hh"

#include <memory>
#include <unordered_set>
#include <utility>
#include <vector>

#include "node.hh"
#include "util.hh"

std::vector<std::shared_ptr<Node>>
populate_nodes_randomly(int node_count, int edge_count) {
  std::vector<std::shared_ptr<Node>> nodes;
  for (auto i = 0; i < node_count; i += 1) {
    nodes.push_back(std::make_shared<Node>(i));
  }

  std::unordered_set<std::pair<int, int>, PairHash<int, int>> edges;
  while (edges.size() < edge_count) {
    auto [a, b] = generate_random_pair(nodes.size());
    auto edge = std::make_pair(a, b);
    if (edges.count(edge))
      continue;

    nodes[a]->m_neighbors.insert(nodes[b]);
    edges.insert(edge);
  }
  return nodes;
}

std::vector<std::pair<std::shared_ptr<Node>, std::shared_ptr<Node>>>
draw_edges(std::vector<std::shared_ptr<Node>> nodes) {
  std::vector<std::pair<std::shared_ptr<Node>, std::shared_ptr<Node>>> edges;
  for (auto n : nodes) {
    for (auto v : n->m_neighbors) {
      edges.push_back({ n, v });
    }
  }
  return edges;
}
