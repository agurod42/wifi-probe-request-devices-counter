#include <string>

using namespace std;

class WiFiProbeRequestPeopleCounter : public PeopleCounter, public WiFiProbeRequestSnifferDelegate {

public:

    WiFiProbeRequestPeopleCounter(const string& interface) {
        sniffer = new WiFiProbeRequestSniffer();
        sniffer->delegate = this;
        snifferInterface = interface;
    }

    void start() {
        sniffer->start(snifferInterface);
        unregisterPersonWhenUnseenFor(1000);
    }

    // WiFiProbeRequestSnifferDelegate methods

    void onProbeRequestSniffed(const WiFiProbeRequestFrame* probeRequest) {
        //cout << "probeRequest" << endl;
        //cout << probeRequest->getSSID() << endl;
        //cout << probeRequest->getMacAddress() << endl;
        //cout << endl;

        MacAddress address = probeRequest->getMacAddress();
        
        if (!isPersonRegistered(address)) {
            //cout << address << " (" << getPeopleCount() + 1 << ")" << endl;
        }
        
        registerPerson(address);
    }

private:

    WiFiProbeRequestSniffer* sniffer;
    string snifferInterface;

};