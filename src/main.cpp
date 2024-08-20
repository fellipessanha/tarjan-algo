#include <algorithm>
#include <iostream>
#include <memory>
#include <unordered_set>
#include <vector>

class Node {
public:
  int m_val;
  std::unordered_set<std::shared_ptr<Node>> m_neighbors;

  Node(int v, std::unordered_set<std::shared_ptr<Node>> neighbors)
      : m_val(v), m_neighbors(neighbors){};

  Node(int v) : m_val(v){};
};

int main() {
  std::vector<std::shared_ptr<Node>> nodes;

  for (auto i = 100; i < 3000; i += 200) {
    nodes.push_back(std::make_shared<Node>(rand() % i));
  }

  for (auto i = 0; i < nodes.size(); i++) {
    auto n_count = rand() % 4;
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

  for (auto n : nodes) {
    std::cout << n->m_val << ", " << n.use_count() << " | ";
    for (auto m : n->m_neighbors) {
      std::cout << m->m_val << ", ";
    }
    std::cout << "\n";
  }

  return 0;
}