#include <iostream>

using namespace std;

int main() {
    int x = 16;
    if (!(x & 1)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}