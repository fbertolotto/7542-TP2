#include "file_processor.hpp"

FileProcessor::FileProcessor(FileContainer &fc) : f_container(fc) {}

void FileProcessor::run() {
    std::string file;
    while((file = f_container.get_file_if_not_empty()) != "") {
        f_reader.load_file(file);
        execute();
    }
}

void FileProcessor::execute() {
    std::string buffer;
    if (f_reader.is_open()) {
        while (f_reader.read(buffer)) f_parser.first_run(buffer);
        f_parser.set_second_run();
        f_reader.reset();

        while (f_reader.read(buffer)) f_parser.second_run(buffer);
        f_parser.print_jumps();
        f_reader.close();
    }
    else {
        std::cout << "Error al abrir el archivo"; 
        return;
    }
    std::map<int,std::vector<int>> values = f_parser.get_jumps();
    DirectedGraph graph(values);
    graph.find_loop();
    reset_all();
}

void FileProcessor::reset_all() {
    f_reader = FileReader();
    f_parser = FileParser();
}