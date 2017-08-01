#include <ctime>
#include <string>

using namespace std;

class WiFiProbeRequestPeopleCounter : public PeopleCounterStrategy, public WiFiProbeRequestSnifferDelegate {

public:

    WiFiProbeRequestPeopleCounter(const string& interface) {
        this->sniffer = new WiFiProbeRequestSniffer();
        this->sniffer->delegate = this;
        this->snifferInterface = interface;
    }

    void start() {
        this->sniffer->start(this->snifferInterface);
    }

    // WiFiProbeRequestSnifferDelegate methods

    void onProbeRequestSniffed(const WiFiProbeRequestFrame* probeRequest) {
        //cout << "probeRequest" << endl;
        //cout << probeRequest->getSSID() << endl;
        //cout << probeRequest->getMacAddress() << endl;
        //cout << endl;

        MacAddress address = probeRequest->getMacAddress();
        
        if (!isPersonRegistered(address)) {
            cout << address << " (" << getPeopleCount() + 1 << ")" << endl;
            cout << endl;
        }
        
        registerPerson(address);
    }

private:

    WiFiProbeRequestSniffer* sniffer;
    string snifferInterface;

};