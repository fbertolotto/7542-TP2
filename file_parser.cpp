#include "file_parser.h"

#include <algorithm>

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

void FileParser::first_run(const std::string &line) {
  line_number++;
  if (line.length() == 0) {
    newlines.insert(line_number);
    return;
  }
  std::vector<std::string> words = split(line, " ");
  std::string first = words[0];
  size_t found_label = first.find(label);
  line_size[line_number] = words.size();
  if (found_label != std::string::npos) {
    // Si tiene label, guardo <label : su_linea>
    // Y resto la cantidad de parametros ya que el label no es una instruccion.
    adresses[first.substr(0, first.length() - 1)] = line_number;
    line_size[line_number] = words.size() - 1;
  }
}

void FileParser::load_possible_jumps(const std::vector<std::string> &line) {
  for (std::string word : line) {
    size_t has_comma = word.find(comma) != std::string::npos;
    if (has_comma) word = word.substr(0, word.length() - 1);

    // Si esa palabra tiene una direccion significa que es una label.
    auto label_adress = adresses.find(word);
    if (label_adress != adresses.end()) {
      auto possibles_jumps = jumps[line_number];  // Vector con las lineas

      // Si la linea del label no existia entre las opciones la agrego.
      if (!std::count(possibles_jumps.begin(), possibles_jumps.end(),
                      label_adress->second))
        jumps[line_number].push_back(label_adress->second);
    }
  }
}

void FileParser::second_run(const std::string &line) {
  line_number++;
  if (line.length() == 0) return;
  std::vector<std::string> words = split(line, " ");

  // Si la cantidad de palabras es igual a la cantidad de parametros entonces
  // esa linea no tiene label y la primer palabra es el comando.
  std::string command = (words.size() == line_size.find(line_number)->second)
                            ? words[0]   // Comando esta en 0
                            : words[1];  // Comando esta en 1
  bool jump_command = command.find(jump) != std::string::npos;

  if (command == ret) {
    jumps[line_number].push_back(-1);  // Si es ret digo que salta a -1.

    // Si NO es un salto o si es un salto que capaz no se ejecuta
    // Tengo que considerar avanzar a la linea siguiente que exista.
    // Esto es saltear todas las lineas vacias que existen.
  } else if (!jump_command || line_size.find(line_number)->second == 3) {
    int aux_number = line_number + 1;
    while ((newlines.find(aux_number) != newlines.cend())) aux_number++;
    jumps[line_number].push_back(aux_number);
  }
  load_possible_jumps(words);
}

void FileParser::set_second_run() { line_number = 0; }

std::map<int, std::vector<int>> FileParser::get_jumps() { return jumps; }

void FileParser::clear() {
  adresses.clear();
  jumps.clear();
  newlines.clear();
  line_size.clear();
  line_number = 0;
}
