#ifndef FILE_READER_H
#define FILE_READER_H

#include <bits/stdc++.h>

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

class FileReader {
 private:
  std::ifstream file;

 public:
  /* Init del lector de archivos */
  FileReader();

  /* Abre el archivo, devuelve 0 en exito. */
  int load_file(const std::string& file_name);

  /* Devuelve un booleano indicando si el archivo esta abierto. */
  bool is_open();

  /* Cierra el archivo. */
  void close();

  /* Lee una linea y la guarda en el buffer. */
  int read(std::string& buffer);

  /* Mueve el puntero al comienzo del archivo. */
  void reset();

  /* No se permiten constructores diferentes al default. */
  FileReader(const FileReader&) = delete;
  FileReader(FileReader&&) = delete;

  /* No se permiten copias por asignación. */
  FileReader& operator=(const FileReader&) = delete;

  /* Se permite por movimiento. */
  FileReader& operator=(FileReader&& other);

  /* Destructor del lector de archivos. */
  ~FileReader();
};

#endif  // FILE_READER_H
