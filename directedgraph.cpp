#include "directedgraph.h"

#include <string>

void DirectedGraph::dfs(int actual) {
  if (actual == -1) return;
  visited.insert(actual);
  if (path.find(actual) != path.end()) {
    loop = true;
    return;
  }
  path.insert(actual);
  for (int &neighbour : graph.at(actual)) dfs(neighbour);
  path.erase(actual);
  return;
}

void DirectedGraph::dfs_base() {
  dfs(graph.begin()->first);
  size = visited.size();
}

DirectedGraph::DirectedGraph(const std::map<int, std::vector<int>> &graph) {
  this->graph = graph;
  loop = false;
  size = 0;
}

bool DirectedGraph::find_loop() {
  dfs_base();
  return loop;
}

bool DirectedGraph::find_unused() { return size != graph.size(); }
