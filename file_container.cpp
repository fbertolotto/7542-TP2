#include "file_container.h"

void FileContainer::add_file(std::string file_name) {
  files.push_back(file_name);
}

std::string FileContainer::get_file_if_not_empty() {
  m.lock();
  if (files.empty()) {
    m.unlock();
    return "";
  }
  std::string file = files.front();
  files.pop_front();
  m.unlock();
  return file;
}
