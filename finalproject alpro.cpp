#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

struct Jabatan {
    string nama;
    int pria;
    int wanita;
    int jumlah;
    float persenPria;
    float persenWanita;
    float persenJumlah;  
};

void hitungTotalKeseluruhan(vector<Jabatan>& jabatans, int &totalPria, int &totalWanita, int &totalPns) {
    totalPria = 0;
    totalWanita = 0;
    totalPns = 0;
    for (const auto& jabatan : jabatans) {
        totalPria += jabatan.pria;
        totalWanita += jabatan.wanita;
    }
    totalPns = totalPria + totalWanita;
}

void hitungPersentase(Jabatan& jabatan, int totalPns) {
    jabatan.jumlah = jabatan.pria + jabatan.wanita;
    jabatan.persenPria = (jabatan.pria * 100.0) / jabatan.jumlah;
    jabatan.persenWanita = (jabatan.wanita * 100.0) / jabatan.jumlah;
    jabatan.persenJumlah = (jabatan.jumlah * 100.0) / totalPns;
}

void tampilkanTabel(const vector<Jabatan>& jabatans, int totalPria, int totalWanita, int totalPns) {
    cout << left << setw(20) << "Jabatan"
         << right << setw(10) << "Pria"
         << setw(10) << "Persen"
         << setw(10) << "Wanita"
         << setw(10) << "Persen"
         << setw(10) << "Jumlah"
         << setw(10) << "Persen" << endl;
    cout << string(80, '-') << endl;

    for (const auto& jabatan : jabatans) {
        cout << left << setw(20) << jabatan.nama
             << right << setw(10) << jabatan.pria
             << setw(10) << fixed << setprecision(2) << jabatan.persenPria
             << setw(10) << jabatan.wanita
             << setw(10) << fixed << setprecision(2) << jabatan.persenWanita
             << setw(10) << jabatan.jumlah
             << setw(10) << fixed << setprecision(2) << jabatan.persenJumlah << endl;
    }

    cout << string(80, '-') << endl;
    cout << left << setw(20) << "Jumlah"
         << right << setw(10) << totalPria
         << setw(10) << fixed << setprecision(2) << (totalPria * 100.0 / totalPns)
         << setw(10) << totalWanita
         << setw(10) << fixed << setprecision(2) << (totalWanita * 100.0 / totalPns)
         << setw(10) << totalPns
         << setw(10) << "100.00" << endl;
}

// Fungsi untuk mengurutkan data berdasarkan jumlah PNS dari terbesar ke terkecil
void urutkanData(vector<Jabatan>& jabatans) {
    sort(jabatans.begin(), jabatans.end(), [](const Jabatan& a, const Jabatan& b) {
        return a.jumlah > b.jumlah;
    });
}

int inputBilanganPositif(const string& prompt) {
    int angka;
    while (true) {
        cout << prompt;
        cin >> angka;
        if (cin.fail() || angka < 0) {
            cin.clear(); // Menghapus kesalahan
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan sisa input
            cout << "Input tidak valid. Masukkan bilangan bulat positif." << endl;
        } else {
            break;
        }
    }
    return angka;
}

int main() {
    vector<Jabatan> jabatans;
    int n;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Tambah Data Jabatan\n";
        cout << "2. Urutkan Data\n";
        cout << "3. Tampilkan Tabel\n";
        cout << "4. Keluar\n";
        cout << "Pilih opsi: ";
        int opsi;
        cin >> opsi;

        if (opsi == 1) {
            // Input jumlah jabatan
            cout << "Masukkan jumlah jabatan: ";
            cin >> n;

            // Input data untuk setiap jabatan
            for (int i = 0; i < n; ++i) {
                Jabatan jabatan;
                cout << "Masukkan nama jabatan: ";
                cin >> ws; // Mengabaikan whitespace
                getline(cin, jabatan.nama);

                jabatan.pria = inputBilanganPositif("Masukkan jumlah PNS pria: ");
                jabatan.wanita = inputBilanganPositif("Masukkan jumlah PNS wanita: ");

                jabatans.push_back(jabatan);
            }
        } else if (opsi == 2) {
            // Urutkan data
            urutkanData(jabatans);
            cout << "Data telah diurutkan dari jumlah terbesar ke terkecil." << endl;
        } else if (opsi == 3) {
            // Tampilkan tabel
            int totalPria, totalWanita, totalPns;
            hitungTotalKeseluruhan(jabatans, totalPria, totalWanita, totalPns);
            for (auto& jabatan : jabatans) {
                hitungPersentase(jabatan, totalPns);
            }
            tampilkanTabel(jabatans, totalPria, totalWanita, totalPns);
        } else if (opsi == 4) {
            // Keluar
            break;
        } else {
            cout << "Opsi tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}
