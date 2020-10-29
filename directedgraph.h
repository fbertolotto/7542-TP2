#include <bits/stdc++.h>

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

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
  DirectedGraph(const std::map<int, std::vector<int>> &graph);
  bool find_loop();
  bool find_unused();
};
