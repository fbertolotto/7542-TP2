#include "directedgraph.hpp"
#include "file_reader.hpp"
#include "parser.hpp"
#include "thread.hpp"
#include "file_container.hpp"

class FileProcessor : public Thread {
    private:
        FileReader f_reader;
        FileParser f_parser;
        FileContainer &f_container;
        void execute();
        void reset_all();

    public:
        FileProcessor(FileContainer &fc);
        virtual void run() override;

};