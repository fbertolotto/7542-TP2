#ifndef RESULTS_CONTAINER_H
#define RESULTS_CONTAINER_H

#include <iostream>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

class ResultsContainer {
 private:
  std::unordered_map<std::string, std::vector<bool>> results;
  std::mutex m;

 public:
  /* Init de Resultados */
  ResultsContainer();

  /* Agrega un resultado, recibe el nombre del archivo, si tuvo un loop y si
  tuvo alguna funcion sin utilizar. */
  void add_result(std::string name, bool loop, bool unused);

  /* Muestra por stdout los resultados que fueron almacenados. */
  void show_results();

  /* No se permiten copias. */
  ResultsContainer& operator=(const ResultsContainer&) = delete;
  ResultsContainer& operator=(ResultsContainer&& other) = delete;

  /* No se permiten constructores diferentes al default. */
  ResultsContainer(const ResultsContainer&) = delete;
  ResultsContainer(ResultsContainer&&) = delete;

  /* Destructor de Resultados. */
  ~ResultsContainer();
};

#endif  // RESULTS_CONTAINER_H
