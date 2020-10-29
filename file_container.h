#ifndef FILE_CONTAINER_H
#define FILE_CONTAINER_H

#include <deque>
#include <iostream>
#include <mutex>
#include <string>

class FileContainer {
 private:
  std::deque<std::string> files;
  std::mutex m;

 public:
  FileContainer() {}
  void add_file(std::string file_name);
  std::string get_file_if_not_empty();
  ~FileContainer() {}
};

#endif  // FILE_CONTAINER_H
