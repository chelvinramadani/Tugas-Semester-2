#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
    double gaji, jumlahAnak, tunjang, potongan, gajiTotal;

    cout << "Masukkan gaji kotor anda" << endl;
    cin >> gaji;
    cout << "Masukkan jumlah anak anda" << endl;
    cin >> jumlahAnak;
    tunjang = jumlahAnak * 100000;
    if (jumlahAnak <= 2) {
        potongan = 0.05 * gaji;
    } else {
        potongan = 0.07 * gaji;
    }
    gajiTotal = gaji - potongan + tunjang;
    cout << "Potongan asuransi anda" << endl;
    cout << potongan << endl;
    cout << "Tunjangan yang anda terima sebesar" << endl;
    cout << tunjang << endl;
    cout << "Gaji yang anda terima adalah" << endl;
    cout << gajiTotal << endl;
    return 0;
}