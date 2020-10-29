#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <vector>

class DirectedGraph {
 private:
  std::map<int, std::vector<int>> graph;
  std::set<int> visited;
  std::set<int> path;
  bool loop;
  size_t size;
  void dfs(int actual);
  void dfs_base();

 public:
  explicit DirectedGraph(const std::map<int, std::vector<int>> &graph);
  bool find_loop();
  bool find_unused();
  ~DirectedGraph() {}
};

#endif  // DIRECTED_GRAPH_H
