#include "node.hh"

#include <memory>

#include <unordered_map>
#include <unordered_set>
#include <vector>

std::vector<std::vector<std::shared_ptr<Node*>>>
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

    // DFS nodes from a random one -- perhaps starting from unvisites.begin()
    // repeat until the stack is empty:
    // there's no neighbor to reach from starting node
    {
      // if the node is unvisited, mark node_idxs[n] as idx, increase idx

      // else, there's a cycle! min the value from n and v, the repeated index
      // in the stack repeat the process above until we reach v
    }
  }
  return {};
}