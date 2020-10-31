#ifndef FILE_PROCESSOR_H
#define FILE_PROCESSOR_H

#include <string>

#include "directedgraph.h"
#include "file_container.h"
#include "file_parser.h"
#include "file_reader.h"
#include "results_container.h"
#include "thread.h"

class FileProcessor : public Thread {
 private:
  FileReader f_reader;
  FileParser f_parser;
  FileContainer& f_container;
  ResultsContainer& results;
  std::string file;

  /* Ejecución principal del procesador de archivos. */
  void execute();

  /* Restablece las estructuras internas previo al analisis de otro archivo. */
  void reset_all();

  /* Analiza los valores obtenidos y los guarda en la clase correspondiente. */
  void analyze_results();

 public:
  /* Init del procesador de archivos, recibe un contenedor de archivos (de donde
  obtendrá los archivos para procesar) y un contenedor de resultados (en donde
  guardara lo obtenido). */
  FileProcessor(FileContainer& fc, ResultsContainer& rs);

  /* Funcion a ejecutar cuando se inicialice un thread con FileProcessor. */
  void run() override;

  /* No se permiten constructores diferentes al default. */
  FileProcessor(const FileProcessor&) = delete;
  FileProcessor(FileProcessor&&) = delete;

  /* No se permiten copias. */
  FileProcessor& operator=(const FileProcessor&) = delete;
  FileProcessor& operator=(FileProcessor&&) = delete;

  /* Destructor del procesador de archivos. */
  ~FileProcessor();
};

#endif  // FILE_PROCESSOR_H
