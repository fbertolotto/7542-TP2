#include <iostream>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

class Results {
 private:
  std::unordered_map<std::string, std::vector<bool>> results;
  std::mutex m;

 public:
  void add_result(std::string name, bool loop, bool unused);
  void show_results();
};
