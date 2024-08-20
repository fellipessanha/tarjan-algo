#pragma once

#include "node.hh"
#include "util.cc"
#include <memory>
#include <iostream>
#include <unordered_set>
#include <vector>

Node::Node(int v, std::unordered_set<std::shared_ptr<Node>> neighbors)
    : m_val(v), m_neighbors(neighbors){};

Node::Node(int v) : m_val(v){};

std::ostream& operator<<(std::ostream& os, const Node& n) {
    std::cout << n.m_val << "\t| ";
    for (auto m : n.m_neighbors) {
      std::cout << m->m_val << ", ";
    }
    return os;
}

std::vector<std::shared_ptr<Node>> populate_nodes_randomly(int node_count, int edge_count) {
	std::vector<std::shared_ptr<Node>> nodes;
  for (auto i = 0; i < node_count; i += 1) {
    nodes.push_back(std::make_shared<Node>(i));
  }

	std::unordered_set<std::pair<int, int>, pairHash<int, int>> edges;
  while (edges.size() < edge_count) {
		auto [a, b] = generate_random_pair(nodes.size());
		auto edge = std::make_pair(a, b);
		if(edges.count(edge)) continue;

		nodes[a]->m_neighbors.insert(nodes[b]);
		edges.insert(edge);
  }
	return nodes;
}
