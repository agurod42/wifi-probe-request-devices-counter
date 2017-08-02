#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <tins/tins.h>

using namespace Tins;

typedef HWAddress<6> MacAddress;

#include "network/WiFiProbeRequestFrame.cpp"
#include "network/WiFiProbeRequestSnifferDelegate.cpp"
#include "network/WiFiProbeRequestSniffer.cpp"

#endif