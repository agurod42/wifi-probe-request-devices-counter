#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class ConsoleLog : public Log {

public:

    void clear() {
        system("clear");
    }

    void writeLine(Loggable* obj) {
        writeLine(obj->toString());
    }

    void writeLine(string str) {
        cout << str << endl;
    }

};