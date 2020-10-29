#ifndef EBPF_H
#define EBPF_H

#include <string>
#include <vector>

#include "file_processor.h"

class eBPF {
 private:
  FileContainer files;
  ResultsContainer rs;
  std::vector<Thread *> threads;

 public:
  /* Init del eBPF, recibe la cantidad de threads que se quiere utilizar. */
  explicit eBPF(int n_threads);

  /* Agrega un archivo para ser procesado */
  void add_file(std::string file);

  /* Comienza a procesar los archivos con la cantidad de threads indicada. */
  void start();

  /* Muestra los resultados obtenidos tras haber analizado los archivos. */
  void show_results();

  /* Destructor del eBPF. */
  ~eBPF();
};

#endif  // EBPF_H
