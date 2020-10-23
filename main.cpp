#include "file_reader.hpp"
#include "parser.hpp"

void dfs(int actual, set<int> &visited,set<int> &path,queue<int> &nodes,map<int,vector<int>> &graph, bool &loop) {
    if (actual == -1) return;
    visited.insert(actual);
    if (path.find(actual) != path.end()) {
        loop = false;
        return;
    }
    path.insert(actual);
    for (auto neighbour : graph.at(actual)) {
        dfs(neighbour,visited,path,nodes,graph,loop);
    }
    path.erase(actual);
    return;
}

void dfs_base(map<int,vector<int>> &graph) {
    queue<int> nodes;
    set<int> visited;
    set<int> path;
    
    int first_key = graph.begin()->first;
    vector<int> neighbours = graph.begin()->second;
    bool loop = true;
    dfs(first_key,visited,path,nodes,graph,loop);

    if (!loop) {
        cout << "Loop found\n";
    } else {
        cout << "No Loop found\n";
    }
    if (visited.size() != graph.size()) {
        cout << "Unused instruction\n";
    } else {
        cout << "All instructions are being used\n";
    }

}

int main () {
    FileReader file;
    FileParser parser;
    string buffer;
    file.load_file("all_addr_modes.bpf");
    if (file.is_open()) {
        while (file.read(buffer)) parser.first_run(buffer);
        parser.set_second_run();
        file.reset();

        while (file.read(buffer)) parser.second_run(buffer);
        parser.print_jumps();
        file.close();
    }
    else cout << "Error al abrir el archivo"; 

    map<int,vector<int>> graph = parser.get_jumps();
    dfs_base(graph);
    return 0;
}