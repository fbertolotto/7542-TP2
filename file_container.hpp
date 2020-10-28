#include <string>
#include <deque>
#include <mutex>
#include <iostream>

class FileContainer {
    private:
        std::deque<std::string> files;
        std::mutex m;
        
    public:
        void add_file(std::string file_name);
        std::string get_file_if_not_empty();
};
