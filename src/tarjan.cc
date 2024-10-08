#include "node.hh"

#include <algorithm>
#include <iostream>
#include <memory>

#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

void
set_strongly_connected_componenets_index(
  std::unordered_map<std::shared_ptr<Node>, int>& node_idxs,
  std::stack<std::shared_ptr<Node>> chain,
  const std::shared_ptr<Node>& node) {
  auto last = node;
  std::cout << "found a cycle: " << node->m_val << " ";

  while (chain.top() != node) {
    std::cout << chain.top()->m_val << " ";
    node_idxs[last] = std::min(node_idxs[chain.top()], node_idxs[last]);
    node_idxs[chain.top()] = node_idxs[last];
    last = chain.top();
    chain.pop();
  }
  std::cout << std::endl;
}

// std::vector<std::vector<std::shared_ptr<Node*>>>
std::unordered_map<std::shared_ptr<Node>, int>
find_strongly_connected_components(std::vector<std::shared_ptr<Node>> nodes) {
  std::unordered_map<std::shared_ptr<Node>, int> node_idxs;
  std::unordered_set<std::shared_ptr<Node>> unvisited;
  for (auto n : nodes) {
    node_idxs[n] = -1;
    unvisited.insert(n);
  }

  int idx = 0;
  // iterate on nodes while not every node has been visited
  while (unvisited.size()) {
    // a new iteration here means a new 'chain',
    // i.e. a new set of nodes which may be strongly linked
    std::stack<std::shared_ptr<Node>> chain;
    std::unordered_set<std::shared_ptr<Node>> in_chain;
    chain.push(*unvisited.begin());
    in_chain.insert(*unvisited.begin());

    // DFS nodes from a random one -- perhaps starting from unvisites.begin()
    // repeat until the stack is empty:
    while (chain.size()) {
      auto node = chain.top();
      // std::cout << "node " << node->m_val << " has " <<
      // node->m_neighbors.size()
      //           << " friends" << std::endl;

      // if the node is unvisited, mark node_idxs[n] as idx, increase idx
      if (node_idxs[node] == -1) {
        node_idxs[node] = idx++;
        unvisited.erase(node);
      }

      // repetition portion: we either iterate on a neighbor of n or remove it
      // from the stack
      if (node->m_neighbors.size()) {
        auto next = node->m_neighbors.back();
        node->m_neighbors.pop_back();
        // std::cout << "next " << next->m_val << " " << std::endl;

        if (in_chain.count(next)) {
          set_strongly_connected_componenets_index(node_idxs, chain, next);
        } else {
          chain.push(next);
          in_chain.insert(next);
        }
      } else {
        in_chain.erase(chain.top());
        chain.pop();
      }
    }
  }
  return node_idxs;
}