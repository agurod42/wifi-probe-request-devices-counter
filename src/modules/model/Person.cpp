#include <chrono>
#include <string>

using namespace std::chrono;

typedef high_resolution_clock::time_point time_p;

template<class T>
class Person : public Loggable {

public:

    T id;
    time_p firstSeen;
    time_p lastSeen;

    Person(T id) {
        this->id = id;
    }

    string toString() const {
        auto firstSeenT = high_resolution_clock::to_time_t(firstSeen);
        auto firstSeenStr = string(ctime(&firstSeenT));
        auto lastSeenT = high_resolution_clock::to_time_t(lastSeen);
        auto lastSeenStr = string(ctime(&lastSeenT));
        return "" + id + " " + firstSeenStr.substr(10, 9) + " " + lastSeenStr.substr(10, 9);
    }

};