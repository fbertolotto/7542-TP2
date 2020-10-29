#include "parser.hpp"

std::vector<std::string> split(std::string msg, std::string delimiter) {
  size_t init = 0, delim_pos;
  std::vector<std::string> buffer;
  while ((delim_pos = msg.find(delimiter, init)) != std::string::npos) {
    std::string word = msg.substr(init, delim_pos - init);
    init = delim_pos + 1;
    if (word.length() == 0) continue;
    buffer.push_back(word);
  }
  buffer.push_back(msg.substr(init));
  return buffer;
}

void FileParser::first_run(const std::string &msg) {
  this->line_number++;
  if (msg.length() == 0) {
    this->newlines.insert(this->line_number);
    return;
  }
  std::vector<std::string> words = split(msg, " ");
  auto first = words[0];
  size_t found_label = first.find(label);
  this->line_size[line_number] = words.size();
  if (found_label != std::string::npos) {
    this->adresses[first.substr(0, first.length() - 1)] = this->line_number;
    this->line_size[this->line_number] = words.size() - 1;
  }
}

void FileParser::load_possible_jumps(std::vector<std::string> &line) {
  for (std::string word : line) {
    size_t has_comma = word.find(this->comma) != std::string::npos;
    if (has_comma) word = word.substr(0, word.length() - 1);

    auto label_adress = this->adresses.find(word);
    if (label_adress != this->adresses.end()) {
      auto possibles_jumps = this->jumps[this->line_number];
      if (!count(possibles_jumps.begin(), possibles_jumps.end(),
                 label_adress->second)) {
        this->jumps[this->line_number].push_back(label_adress->second);
      }
    }
  }
}

void FileParser::second_run(const std::string &msg) {
  this->line_number++;
  if (msg.length() == 0) return;
  std::vector<std::string> words = split(msg, " ");
  std::string command =
      (words.size() == this->line_size.find(this->line_number)->second)
          ? words[0]
          : words[1];
  bool jump_command = command.find(jump) != std::string::npos;

  if (command == this->ret) {
    this->jumps[this->line_number].push_back(-1);
  } else if (!jump_command ||
             this->line_size.find(this->line_number)->second == 3) {
    int aux_number = this->line_number + 1;
    while ((this->newlines.find(aux_number) != this->newlines.cend())) {
      aux_number++;
    }
    this->jumps[this->line_number].push_back(aux_number);
  }
  this->load_possible_jumps(words);
}

void FileParser::set_second_run() { this->line_number = 0; }

std::map<int, std::vector<int>> FileParser::get_jumps() { return this->jumps; }
