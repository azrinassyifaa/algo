#include <iostream>
using namespace std;

// Struct Mahasiswa
struct Mahasiswa {
    string nama;
    float nilai_akhir;
};

int main() {
    Mahasiswa mhs[5];   // Array untuk 5 mahasiswa
    float total = 0.0;
    float rata_rata;

    cout << "=== Input Data 5 Mahasiswa ===" << endl;

    // Input data mahasiswa
    for (int i = 0; i < 5; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;

        cout << "Masukkan Nama         : ";
        getline(cin, mhs[i].nama);

        cout << "Masukkan Nilai Akhir  : ";
        cin >> mhs[i].nilai_akhir;
        cin.ignore(); // Membersihkan buffer agar getline selanjutnya tidak terlewat

        total += mhs[i].nilai_akhir;
    }

    // Hitung rata-rata
    rata_rata = total / 5;

    // Tampilkan hasil
    cout << "\n=== Data Mahasiswa ===" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Nama  : " << mhs[i].nama << endl;
        cout << "Nilai : " << mhs[i].nilai_akhir << endl;
        cout << "-----------------------------" << endl;
    }

    cout << "Rata-rata Nilai Kelas : " << rata_rata << endl;

    return 0;
}