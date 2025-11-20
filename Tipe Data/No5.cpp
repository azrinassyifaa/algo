#include <iostream>
using namespace std;

enum JenisAkun { Dokter = 1, Polisi };

int main() {
    int pilihan;
    cout << "Pilih jenis akun:\n";
    cout << "1. dokter\n";
    cout << "2. polisi\n";
    cout << "Masukkan pilihan: ";
    cin >> pilihan;

    JenisAkun akun = static_cast<JenisAkun>(pilihan);

    if (akun == Dokter)
        cout << "Anda memilih akun dokter." << endl;
    else if (akun == Polisi)
        cout << "Anda memilih akun polisi." << endl;
    else
        cout << "Pilihan tidak valid." << endl;

    return 0;
}