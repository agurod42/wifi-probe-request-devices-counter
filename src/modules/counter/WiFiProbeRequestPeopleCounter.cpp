#include <string>

#include <iostream> // temp

using namespace std;

class WiFiProbeRequestPeopleCounter : public PeopleCounter<MacAddress>, public WiFiProbeRequestSnifferDelegate {

public:

    WiFiProbeRequestPeopleCounter(const string& interface) {
        sniffer = new WiFiProbeRequestSniffer();
        sniffer->delegate = this;
        snifferInterface = interface;
    }

    void start() {
        sniffer->start(snifferInterface);
    }

    // WiFiProbeRequestSnifferDelegate methods

    void onProbeRequestSniffed(const WiFiProbeRequestFrame* probeRequest) {
        MacAddress address = probeRequest->getMacAddress();

        registerPerson(new Person<MacAddress>(address));

        log->clear();
        forEachPerson([this](Person<MacAddress>* person) {
            log->writeLine(person);
        });
    }

private:

    WiFiProbeRequestSniffer* sniffer;
    string snifferInterface;

    Log* log = new ConsoleLog();

};