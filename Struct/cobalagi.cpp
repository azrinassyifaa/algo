#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float nilai;
};

void tampilData(Mahasiswa m) {
    cout << "Nama  : " << m.nama << endl;
    cout << "NIM   : " << m.nim << endl;
    cout << "Nilai : " << m.nilai << endl;
    cout << "-----------------------------" << endl;
}

int main() {
    int jumlah;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlah;
    cin.ignore();

    Mahasiswa mhs[jumlah];

    for (int i = 0; i < jumlah; i++) {
        cout << "\nMasukkan data mahasiswa ke-" << i + 1 << endl;
        cout << "Nama  : ";
        getline(cin, mhs[i].nama);
        cout << "NIM   : ";
        getline(cin, mhs[i].nim);
        cout << "Nilai : ";
        cin >> mhs[i].nilai;
        cin.ignore();
    }

    cout << "\n=== DATA MAHASISWA ===\n";
    for (int i = 0; i < jumlah; i++) {
        tampilData(mhs[i]);
    }

    return 0;
}