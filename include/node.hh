#pragma once

#include <memory>
#include <unordered_set>

class Node {
public:
  int m_val;
  std::unordered_set<std::shared_ptr<Node>> m_neighbors;

  Node(int v, std::unordered_set<std::shared_ptr<Node>> neighbors);

  Node(int v);

  friend std::ostream& operator<<(std::ostream& os, const Node& n);
};
