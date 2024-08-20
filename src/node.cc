#pragma once

#include "node.hh"
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

void populate_nodes_randomly(std::vector<std::shared_ptr<Node>> &nodes, int node_count, int max_neighbors) {
  for (auto i = 0; i < node_count; i += 1) {
    nodes.push_back(std::make_shared<Node>(i));
  }

  for (auto i = 0; i < nodes.size(); i++) {
    auto n_count = rand() % max_neighbors;
    std::vector<int> possible;
    for (auto j = 0; j < nodes.size(); j++) {
      if (i != j)
        possible.push_back(j);
    }

    for (auto j = 0; j < n_count; j++) {
      auto chosen_idx = rand() % possible.size();
      std::swap(possible[chosen_idx], possible.back());
      nodes[i]->m_neighbors.emplace(nodes[possible.back()]);

      possible.pop_back();
    }
  }
}
