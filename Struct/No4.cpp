#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;


    string nim;
    float nilai;
};

void tampilData(Mahasiswa m) {
    cout << "\n=== Data Mahasiswa ===\n";
    cout << "Nama  : " << m.nama << endl;
    cout << "NIM   : " << m.nim << endl;
    cout << "Nilai : " << m.nilai << endl;
}

int main() {
    Mahasiswa mhs;

    cout << "Masukkan Nama: ";
    getline(cin, mhs.nama);
    cout << "Masukkan NIM: ";
    getline(cin, mhs.nim);
    cout << "Masukkan Nilai: ";
    cin >> mhs.nilai;

    tampilData(mhs);

    return 0;
}