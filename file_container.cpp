#include "file_container.h"

FileContainer::FileContainer() {}

FileContainer::~FileContainer() {}

void FileContainer::add_file(std::string file_name) {
  files.push_back(file_name);
}

std::string FileContainer::get_file() {
  std::unique_lock<std::mutex> lock(m);
  if (files.empty()) return "";
  std::string file = files.front();
  files.pop_front();
  m.unlock();
  return file;
}
