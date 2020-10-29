#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <map>
#include <set>
#include <string>
#include <vector>

class FileParser {
 private:
  // Constantes
  std::string label = ":";
  std::string jump = "j";
  std::string comma = ",";
  std::string ret = "ret";

  int line_number = 0;
  std::map<std::string, int> adresses;
  std::map<int, std::vector<int>> jumps;
  std::set<int> newlines;
  std::map<int, size_t> line_size;
  /* Carga para una linea del archivo, todos los posibles saltos. */
  void load_possible_jumps(const std::vector<std::string> &line);

 public:
  /* Init del parseador de archivos. */
  FileParser() {}

  /* Primera ejecucion del parseador. Genera las tablas de simbolos
  necesarias para el parseo. */
  void first_run(const std::string &line);

  /* Prepara el archivo para la segunda leida. */
  void set_second_run();

  /* Segunda ejecucion, analiza y parsea cada linea, para determinar
  los posibles saltos de cada una. */
  void second_run(const std::string &line);

  /* Limpia el parseador. */
  void clear();

  /* Devuelve un mapa <linea : saltos> */
  std::map<int, std::vector<int>> get_jumps();

  /* Destructor del parseador de archivos. */
  ~FileParser() {}
};

#endif  // FILE_PARSER_H
