#include <chrono>
#include <thread>

#include <cstdlib> // temp
#include <iostream> //temp
#include <string> //temp

using namespace std;
using namespace std::chrono;

typedef high_resolution_clock::time_point time_p;

class PeopleCounter {

public:

    virtual void start() = 0;

protected:

    // people variable access methods

    int getPeopleCount() {
        return people.size();
    }

    bool isPersonRegistered(MacAddress address) {
        return people.count(address) == 1;
    }

    void registerPerson(MacAddress address) {
        time_p now = high_resolution_clock::now();
        
        if (!isPersonRegistered(address)) {
            maxDiffs.insert(make_pair(address, 0)); // temp
            people.insert(make_pair(address, now));
        }
        else {
            people[address] = now;
        }
    }

    void unregisterPerson(MacAddress address) {
        people.erase(address);
    }

    // people unregistering process
    
    void unregisterPersonWhenUnseenFor(int milliseconds) {
        thread unregisterPersonWhenUnseenForThread(&PeopleCounter::unregisterPersonWhenUnseenForLoop, this, milliseconds);
        unregisterPersonWhenUnseenForThread.detach();
    }

    void unregisterPersonWhenUnseenForLoop(int sleepMilliseconds) {
        while (1) {
            map<MacAddress, time_p>::iterator it;
            
            system("clear"); // clera screen (temp)
            cout << "MacAddress" << "\t\t" << "LastSeen" << "\t\t\t" << "Delta (ms)" << "\t" << "MaxDelta" << endl;

            for (it = people.begin(); it != people.end(); ++it) {
                auto diff = duration_cast<milliseconds>(high_resolution_clock::now() - it->second).count();
                auto lastSeen = high_resolution_clock::to_time_t(it->second);
                auto lastSeenStr = string(ctime(&lastSeen));

                if (diff > maxDiffs[it->first]) {
                    maxDiffs[it->first] = diff;
                }

                cout << it->first << "\t" << lastSeenStr.substr(0, lastSeenStr.length() - 1) << "\t" << diff << "\t\t" << maxDiffs[it->first] << endl;
            
                // if we saw this person 2 mins ago we can assume he has leave the place
                //if (diff > 1000 * 120) {
                //    cout << it->first << " last scanned ";
                //    cout << diff;
                //    cout << "ms ago (did he leave?)" << endl;
                //}
            }
            
            this_thread::sleep_for(chrono::milliseconds(sleepMilliseconds));
        }
    }

private:

    map<MacAddress, time_p> people;

    map<MacAddress, int> maxDiffs; // temp

};