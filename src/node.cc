#include "node.hh"

#include <iostream>
#include <memory>
#include <unordered_set>
#include <vector>

Node::Node(int v, std::unordered_set<std::shared_ptr<Node>> neighbors)
  : m_val(v)
  , m_neighbors(neighbors){};

Node::Node(int v)
  : m_val(v){};

std::ostream&
operator<<(std::ostream& os, const Node& n) {
  std::cout << n.m_val << "\t| ";
  for (auto m : n.m_neighbors) {
    std::cout << m->m_val << ", ";
  }
  return os;
}
