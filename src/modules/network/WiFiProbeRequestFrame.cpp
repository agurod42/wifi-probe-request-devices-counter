#include <string>

using namespace std;

class WiFiProbeRequestFrame {

public:

    WiFiProbeRequestFrame(PDU* pdu) {
        const Dot11ProbeRequest& probeRequest = pdu->rfind_pdu<Dot11ProbeRequest>();
        
        this->managementFrame = &pdu->rfind_pdu<Dot11ManagementFrame>();
    }

    MacAddress getMacAddress() const {
        if (!this->managementFrame->from_ds() && !this->managementFrame->to_ds()) {
            return this->managementFrame->addr2();
        }
        else if (!this->managementFrame->from_ds() && this->managementFrame->to_ds()) {
            return this->managementFrame->addr2();
        }
        else {
            return this->managementFrame->addr3();
        }
    }

    string getSSID() const {
        return this->managementFrame->ssid();
    }

private:

    const Dot11ManagementFrame* managementFrame;

};