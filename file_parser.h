#include <map>
#include <set>
#include <string>
#include <vector>

class FileParser {
 private:
  std::string label = ":";
  std::string jump = "j";
  std::string comma = ",";
  std::string ret = "ret";
  int line_number = 0;
  std::map<std::string, int> adresses;
  std::map<int, std::vector<int>> jumps;
  std::set<int> newlines;
  std::map<int, size_t> line_size;
  void load_possible_jumps(std::vector<std::string> &line);

 public:
  void first_run(const std::string &msg);
  void set_second_run();
  void second_run(const std::string &msg);
  std::map<int, std::vector<int>> get_jumps();
};
