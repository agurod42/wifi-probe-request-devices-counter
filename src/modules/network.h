#ifndef NETWORK_H
#define NETWORK_H

#include <tins/tins.h>

using namespace Tins;

typedef HWAddress<6> MacAddress;

#include "network/WiFiProbeRequestFrame.cpp"
#include "network/WiFiProbeRequestSnifferDelegate.cpp"
#include "network/WiFiProbeRequestSniffer.cpp"

#endif