#include "file_processor.h"

#include <map>
#include <vector>

FileProcessor::FileProcessor(FileContainer &fc, ResultsContainer &rs)
    : f_container(fc), results(rs) {}

void FileProcessor::run() {
  std::string file;
  while ((file = f_container.get_file_if_not_empty()) != "") {
    if (f_reader.load_file(file)) return;
    this->file = file;
    execute();
  }
}

void FileProcessor::execute() {
  std::string buffer;
  while (f_reader.read(buffer)) f_parser.first_run(buffer);
  f_parser.set_second_run();
  f_reader.reset();

  while (f_reader.read(buffer)) f_parser.second_run(buffer);
  f_reader.close();
  analyze_results();
  reset_all();
}

void FileProcessor::reset_all() { f_parser.clear(); }

void FileProcessor::analyze_results() {
  std::map<int, std::vector<int>> values = f_parser.get_jumps();
  DirectedGraph graph(values);
  bool loop = graph.find_loop();
  bool unused = graph.find_unused();
  results.add_result(file, loop, unused);
}
