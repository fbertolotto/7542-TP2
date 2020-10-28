#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <bits/stdc++.h> 

class DirectedGraph {
    private:
        std::map<int,std::vector<int>> graph;
        std::set<int> visited;
        std::set<int> path;
        bool loop;
        size_t size;
        void dfs(int actual);
        void dfs_base();

    public:
        DirectedGraph(std::map<int,std::vector<int>> &graph);
        bool find_loop();
        int get_size();
};


