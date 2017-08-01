#include <iostream>
#include <string>

using namespace std;

int help(char* argv[]) {
    cout << "Usage: " << *argv << " <interface>" << endl;
    return 1;
}