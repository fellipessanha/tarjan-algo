
#include "node.hh"
#include <vector>

std::vector<std::vector<std::shared_ptr<Node*>>>
find_strongly_connected_components(std::vector<std::shared_ptr<Node>> nodes);