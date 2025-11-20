#include <iostream>
#include <string>
using namespace std;

int main() {
    string namaDepan, namaBelakang;

    cout << "Masukkan nama depan: ";
    cin >> namaDepan;
    cout << "Masukkan kelas belakang: ";
    cin >> namaBelakang;

    string kalimat = "Halo " + namaDepan + " " + namaBelakang + "! Selamat belajar algoritma.";
    cout << kalimat << endl;

    return 0;
}