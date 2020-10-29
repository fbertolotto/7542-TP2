#include "file_processor.hpp"


int main (int argc, char** argv ) {

    FileContainer files;
    Results rs;
    int n = atoi(argv[1]);

    for (int i = 2; i < argc; i++) {
        files.add_file(argv[i]);
    }

    std::vector<Thread*> threads;
    for (int t = 0; t < n; t++) {
        threads.push_back(new FileProcessor(files,rs));
    }
    
    for (auto thread : threads) {
        thread->start();
    }
    for (auto thread : threads) {
        thread->join();
    }
    rs.show_results();
    return 0;
}