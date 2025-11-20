#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    float nilai_akhir;
};

int main() {
    Mahasiswa mhs[5];
    float total = 0, rata;

    cout << "=== Input Data 5 Mahasiswa ===" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama         : ";
        getline(cin, mhs[i].nama);
        cout << "Nilai Akhir  : ";
        cin >> mhs[i].nilai_akhir;
        cin.ignore(); 

        total += mhs[i].nilai_akhir;
    }

    rata = total / 5;

    cout << "\n=====================================\n";
    cout << "Daftar Nilai Mahasiswa" << endl;
    cout << "=====================================\n";
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << mhs[i].nama 
             << " - Nilai Akhir: " << mhs[i].nilai_akhir << endl;
    }

    cout << "\nRata-rata Nilai Kelas: " << rata << endl;

    return 0;
}