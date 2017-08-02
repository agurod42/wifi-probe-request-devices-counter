#include <string>
#include <thread>

#include <fstream> // temp
#include <iostream> // temp

using namespace std;

class WiFiProbeRequestSniffer {

public:

    WiFiProbeRequestSnifferDelegate* delegate;

    void start(const string& interface) {
        thread snifferLoopThread(&WiFiProbeRequestSniffer::snifferLoop, this, interface);
        snifferLoopThread.detach();
    }

private:

    void snifferLoop(const string& interface) {
        SnifferConfiguration config;
        config.set_promisc_mode(true);
        config.set_rfmon(true);

        Sniffer sniffer(interface, config);

        while (1) {
            try {
                const PDU* pdu = sniffer.next_packet();
                snifferLoopHandler(pdu);
                delete pdu;
            }
            catch (exception ex) {
                // keep moving
                ofstream exFile;
                exFile.open("error.log");
                exFile << ex.what();
                exFile.close();
            }
        }
    }

    void snifferLoopHandler(const PDU* pdu) {
        const WiFiProbeRequestFrame* probeRequest = new WiFiProbeRequestFrame(pdu);
        
        if (this->delegate != NULL) {
            this->delegate->onProbeRequestSniffed(probeRequest);
        }
    }

};