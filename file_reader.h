#include <bits/stdc++.h>

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

class FileReader {
 private:
  std::ifstream file;

 public:
  void load_file(const std::string &file_name);
  bool is_open();
  void close();
  int read(std::string &buffer);
  void reset();
};
