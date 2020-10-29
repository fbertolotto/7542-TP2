#include "ebpf.h"

#include <string>
eBPF::eBPF(int n_threads) {
  for (int t = 0; t < n_threads; t++)
    threads.push_back(new FileProcessor(files, rs));
}

void eBPF::add_file(std::string file) { files.add_file(file); }

void eBPF::start() {
  for (auto &thread : threads) thread->start();
  for (auto &thread : threads) thread->join();
}

void eBPF::show_results() { rs.show_results(); }

eBPF::~eBPF() {
  for (auto &thread : threads) delete thread;
}
