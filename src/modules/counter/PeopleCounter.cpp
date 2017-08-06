#include <chrono>

using namespace std::chrono;

template<class T>
class PeopleCounter {

public:

    virtual void start() = 0;

protected:

    // people variable access methods

    template<typename F>
    void forEachPerson(F action) {
        typename map<T, Person<T>*>::iterator it;

        for (it = people.begin(); it != people.end(); ++it) {
            action(it->second);
        }
    }

    int getPeopleCount() {
        return people.size();
    }

    bool isPersonRegistered(Person<T>* person) {
        return people.count(person->id) == 1;
    }

    void registerPerson(Person<T>* person) {
        time_p now = high_resolution_clock::now();
        
        if (!isPersonRegistered(person)) {
            person->firstSeen = now;
            person->lastSeen = now;
            people.insert(make_pair(person->id, person));
        }
        else {
            people[person->id]->lastSeen = now;
        }
    }

    void unregisterPerson(T id) {
        people.erase(id);
    }

private:

    map<T, Person<T>*> people;

};