#include <chrono>
using namespace std::chrono;

typedef high_resolution_clock::time_point time_p;

class PeopleCounterStrategy {

public:

    virtual void start() = 0;

protected:

    int getPeopleCount() {
        return people.size();
    }

    bool isPersonRegistered(MacAddress address) {
        return people.count(address) == 1;
    }

    void registerPerson(MacAddress address) {
        time_p now = high_resolution_clock::now();
        
        if (!isPersonRegistered(address)) {
            people.insert(make_pair(address, now));
        }
        else {
            people[address] = now;
        }
    }

private:

    map<MacAddress, time_p> people;

};