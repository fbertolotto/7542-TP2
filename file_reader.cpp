#include "file_reader.hpp"

void FileReader::load_file (string file_name) {
    this->file.open(file_name);
}

bool FileReader::is_open () {
    return this->file.is_open();
}

void FileReader::close() {
    this->file.close();
}

int FileReader::read(string &buffer) {
    if(!getline(this->file,buffer)) return 0;
    return 1;
}

void FileReader::reset() {
    this->file.clear();
    this->file.seekg(0);
}