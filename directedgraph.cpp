#include "directedgraph.h"

void DirectedGraph::dfs(int actual) {
  if (actual == -1) return;
  this->visited.insert(actual);
  if (this->path.find(actual) != this->path.end()) {
    this->loop = true;
    return;
  }
  this->path.insert(actual);
  for (auto neighbour : this->graph.at(actual)) {
    this->dfs(neighbour);
  }
  path.erase(actual);
  return;
}

void DirectedGraph::dfs_base() {
  this->dfs(this->graph.begin()->first);
  this->size = this->visited.size();

  /*
      if (this->loop) {
          std::cout << "Loop found\n";
      } else {
          std::cout << "No Loop found\n";
      }
      if (this->size != this->graph.size()) {
          std::cout << "Unused instruction\n";
      } else {
          std::cout << "All instructions are being used\n";
      }
  */
}

DirectedGraph::DirectedGraph(const std::map<int, std::vector<int>> &graph) {
  this->graph = graph;
  loop = false;
  size = 0;
}

bool DirectedGraph::find_loop() {
  this->dfs_base();
  return this->loop;
}

bool DirectedGraph::find_unused() { return this->size != this->graph.size(); }
