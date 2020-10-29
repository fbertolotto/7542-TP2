#ifndef FILE_PROCESSOR_H
#define FILE_PROCESSOR_H

#include <string>

#include "directedgraph.h"
#include "file_container.h"
#include "file_parser.h"
#include "file_reader.h"
#include "results.h"
#include "thread.h"

class FileProcessor : public Thread {
 private:
  FileReader f_reader;
  FileParser f_parser;
  FileContainer &f_container;
  Results &results;
  std::string file;
  void execute();
  void reset_all();
  void analyze_results();

 public:
  FileProcessor(FileContainer &fc, Results &rs);
  void run() override;
  ~FileProcessor() {}
};

#endif  // FILE_PROCESSOR_H
