#include <thread>

class Thread {
    private:
        std::thread thread;
 
    public:
        Thread () {}
        void start();
        void join();
        virtual void run() = 0;
};