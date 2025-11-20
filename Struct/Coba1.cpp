#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float nilai;
};

int main() {
    Mahasiswa mhs;

    cout << "Masukkan Nama: ";
    getline(cin, mhs.nama);
    cout << "Masukkan NIM: ";
    getline(cin, mhs.nim);
    cout << "Masukkan Nilai: ";
    cin >> mhs.nilai;

    cout << "\n=== Data Mahasiswa ===\n";
    cout << "Nama  : " << mhs.nama << endl;
    cout << "NIM   : " << mhs.nim << endl;
    cout << "Nilai : " << mhs.nilai << endl;

    return 0;
}