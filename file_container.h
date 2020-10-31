#ifndef FILE_CONTAINER_H
#define FILE_CONTAINER_H

#include <deque>
#include <iostream>
#include <mutex>
#include <string>

class FileContainer {
 private:
  std::deque<std::string> files;
  std::mutex m;

 public:
  /* Init del contenedor de archivos. */
  FileContainer();

  /* Agrega el nombre del archivo a una cola de archivos. */
  void add_file(std::string file_name);

  /* Devuelve un nombre de archivo si la cola de estos no
  esta vacia. */
  std::string get_file();

  /* No se permiten copias. */
  FileContainer& operator=(const FileContainer&) = delete;
  FileContainer& operator=(FileContainer&&) = delete;

  /* No se permiten constructores diferentes al default. */
  FileContainer(const FileContainer&) = delete;
  FileContainer(FileContainer&&) = delete;

  /* Destructor del contenedor de archivos. */
  ~FileContainer();
};

#endif  // FILE_CONTAINER_H
