#include "file_processor.hpp"

int main () {
    FileContainer fc;
    fc.add_file("all_addr_modes.bpf");
    fc.add_file("not_exec.bpf");
    fc.add_file("test_insta.bpf");
    fc.add_file("test.bpf");
    FileProcessor first(fc);
    FileProcessor second(fc);

    first.start();
    second.start();
    first.join();
    second.join();
    return 0;
}