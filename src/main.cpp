#include "help.cpp"
#include "modules/counter.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) return help(argv);

    PeopleCounterStrategy* counter = new WiFiProbeRequestPeopleCounter(argv[1]);
    counter->start();

    while(1);
}