#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <bits/stdc++.h> 
using namespace std;

class FileReader {
    private:
        ifstream file;

    public:
        void load_file(string file_name);
        bool is_open();
        void close();
        int read(string &buffer);
        void reset();
};