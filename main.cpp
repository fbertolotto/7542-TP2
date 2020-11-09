#include <string>

#include "ebpf.h"

int main(int argc, char **argv) {
  if (argc == 1) return 0;
  int n = std::stoi(argv[1]);
  eBPF checker(n);
  for (int i = 2; i < argc; i++) checker.add_file(argv[i]);
  checker.start();
  checker.show_results();
  return 0;
}
