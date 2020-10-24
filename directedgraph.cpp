#include "directedgraph.hpp"

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

    this->loop = false;
    this->dfs(this->graph.begin()->first);
    this->size = this->visited.size();
    if (this->loop) {
        cout << "Loop found\n";
    } else {
        cout << "No Loop found\n";
    }
    if (this->size != this->graph.size()) {
        cout << "Unused instruction\n";
    } else {
        cout << "All instructions are being used\n";
    }

}

DirectedGraph::DirectedGraph(map<int,vector<int>> &graph) {
    this->graph = graph;
}

bool DirectedGraph::find_loop() {
    this->dfs_base();
    return this->loop;
}