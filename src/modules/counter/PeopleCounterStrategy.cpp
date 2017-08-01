#include <ctime>

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
        if (!isPersonRegistered(address)) {
            people.insert(make_pair(address, time(0)));
        }
        else {
            people[address] = time(0);
        }
    }

private:

    map<MacAddress, time_t> people;

};