#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <bits/stdc++.h> 
using namespace std;

class DirectedGraph {
    private:
        map<int,vector<int>> graph;
        set<int> visited;
        set<int> path;
        bool loop;
        size_t size;
        void dfs(int actual);
        void dfs_base();

    public:
        DirectedGraph(map<int,vector<int>> &graph);
        bool find_loop();
        int get_size();
};


