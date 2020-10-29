#ifndef EBPF_H
#define EBPF_H

#include <string>
#include <vector>

#include "file_processor.h"
class eBPF {
 private:
  FileContainer files;
  Results rs;
  std::vector<Thread *> threads;

 public:
  explicit eBPF(int n_threads);
  void add_file(std::string file);
  void start();
  void show_results();
  ~eBPF();
};

#endif  // EBPF_H
