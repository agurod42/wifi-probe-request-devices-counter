#include <string>
#include <thread>

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
        sniffer.sniff_loop(make_sniffer_handler(this, &WiFiProbeRequestSniffer::snifferLoopHandler));
    }

    bool snifferLoopHandler(PDU& pdu) {
        try {
            const WiFiProbeRequestFrame* probeRequest = new WiFiProbeRequestFrame(&pdu);
            
            if (this->delegate != NULL) {
                this->delegate->onProbeRequestSniffed(probeRequest);
            }
        }
        catch (...) {
            // keep moving
        }
        
        return true;
    }

};