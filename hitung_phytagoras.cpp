#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

// Headers
string toString (double);
int toInt (string);
double toDouble (string);
void phytagoras(int a, int b);

int main() {
    int a, b;

    cout << "masukkan sisi tegak segitiga" << endl;
    cin >> a;
    cout << "masukkan sisi datar segitiga" << endl;
    cin >> b;
    cout << "sisi miring segitiga adalah" << endl;
    phytagoras(a, b);
    return 0;
}

void phytagoras(int a, int b) {
    int c;

    c = (int) sqrt(pow(a, 2) + pow(b, 2));
    cout << c << endl;
}

// The following implements type conversion functions.
string toString (double value) { //int also
    stringstream temp;
    temp << value;
    return temp.str();
}

int toInt (string text) {
    return atoi(text.c_str());
}

double toDouble (string text) {
    return atof(text.c_str());
}
