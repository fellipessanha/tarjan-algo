
#include "node.hh"
#include <unordered_map>
#include <vector>

// std::vector<std::vector<std::shared_ptr<Node*>>>
std::unordered_map<std::shared_ptr<Node>, int>
find_strongly_connected_components(std::vector<std::shared_ptr<Node>> nodes);