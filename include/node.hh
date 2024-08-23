#pragma once

#include <memory>
#include <vector>

class Node {
public:
  int m_val;
  std::vector<std::shared_ptr<Node>> m_neighbors;

  Node(int v, std::vector<std::shared_ptr<Node>> neighbors);

  Node(int v);

  friend std::ostream& operator<<(std::ostream& os, const Node& n);
};
