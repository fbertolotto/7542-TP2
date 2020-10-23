#include <string>
#include <bits/stdc++.h> 
using namespace std;

class FileParser {
    private:
        string label = ":";
        string jump = "j";
        string comma = ",";
        string ret = "ret";
        int line_number = 0;
        map<string,int> adresses;
        map<int,vector<int>> jumps;
        set<int> newlines;
        map<int,size_t> line_size;
        void load_possible_jumps(vector<string> &line);

    public:
        void first_run(string &msg);
        void set_second_run();
        void second_run(string &msg);
        void print_jumps();
        map<int,vector<int>> get_jumps();
};