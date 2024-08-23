#pragma once

#include <memory>
#include <unordered_set>
#include <utility>
#include <vector>

#include "node.hh"
#include "util.hh"

std::vector<std::shared_ptr<Node>>
populate_nodes_randomly(int node_count, int edge_count);

std::vector<std::pair<std::shared_ptr<Node>, std::shared_ptr<Node>>>
draw_edges(std::vector<std::shared_ptr<Node>> nodes);

std::vector<std::shared_ptr<Node>>
generate_simple_cycled_graph();