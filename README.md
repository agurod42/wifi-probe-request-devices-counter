# people-wifi-counter

## Build

### Linux

1. Install dependencies

    apt-get install cmake g++ gdb git libpcap-dev libssl-dev

2. Compile libtins

    git clone https://github.com/mfontanini/libtins.git
    cd libtins
    mkdir build
    cd build
    cmake ../ -DLIBTINS_ENABLE_CXX11=1
    make
    make install