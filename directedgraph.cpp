#include "directedgraph.h"

#include <string>
#include <utility>

DirectedGraph::DirectedGraph(const std::map<int, std::vector<int>>& graph) {
  this->graph = graph;
  loop = false;
  size = 0;
}

DirectedGraph::~DirectedGraph() {}

void DirectedGraph::dfs(int actual) {
  if (actual == -1) return;
  visited.insert(actual);
  if (path.find(actual) != path.end()) {
    loop = true;
    return;
  }
  path.insert(actual);
  for (int& neighbour : graph.at(actual)) dfs(neighbour);
  path.erase(actual);
  return;
}

void DirectedGraph::dfs_base() {
  dfs(graph.begin()->first);
  size = visited.size();
}

/* Se permiten copias */
DirectedGraph::DirectedGraph(const DirectedGraph& other) {
  this->graph = other.graph;
  this->visited = other.visited;
  this->path = other.path;
  this->loop = other.loop;
  this->size = other.size;
}

DirectedGraph& DirectedGraph::operator=(const DirectedGraph& other) {
  this->graph = other.graph;
  this->visited = other.visited;
  this->path = other.path;
  this->loop = other.loop;
  this->size = other.size;
  return *this;
}

DirectedGraph& DirectedGraph::operator=(DirectedGraph&& other) {
  this->graph = std::move(other.graph);
  this->visited = std::move(other.visited);
  this->path = std::move(other.path);
  this->loop = other.loop;
  this->size = other.size;
  other.loop = false;
  other.size = 0;
  return *this;
}

bool DirectedGraph::find_loop() {
  dfs_base();
  return loop;
}

bool DirectedGraph::find_unused() { return size != graph.size(); }
