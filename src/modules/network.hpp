#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <tins/tins.h>

using namespace Tins;

typedef HWAddress<6> MacAddress;

string operator+(const string& lhs, const MacAddress& rhs) {
    return lhs + rhs.to_string();
}

#include "network/WiFiProbeRequestFrame.cpp"
#include "network/WiFiProbeRequestSnifferDelegate.cpp"
#include "network/WiFiProbeRequestSniffer.cpp"

#endif