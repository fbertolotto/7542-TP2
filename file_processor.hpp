#include "directedgraph.hpp"
#include "file_container.hpp"
#include "file_reader.hpp"
#include "parser.hpp"
#include "results.hpp"
#include "thread.hpp"

class FileProcessor : public Thread {
 private:
  FileReader f_reader;
  FileParser f_parser;
  FileContainer &f_container;
  Results &results;
  std::string file;
  void execute();
  void reset_all();

 public:
  FileProcessor(FileContainer &fc, Results &rs);
  virtual void run() override;
};
