#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <bits/stdc++.h> 

class FileReader {
    private:
        std::ifstream file;

    public:
        void load_file(std::string file_name);
        bool is_open();
        void close();
        int read(std::string &buffer);
        void reset();
};