#include "file_reader.hpp"
#include "parser.hpp"
#include "directedgraph.hpp"

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
    else {
        cout << "Error al abrir el archivo"; 
        return 0;
    }
    map<int,vector<int>> values = parser.get_jumps();
    DirectedGraph graph(values);
    graph.find_loop();
    return 0;
}