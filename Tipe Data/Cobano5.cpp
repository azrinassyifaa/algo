#include <iostream>
using namespace std;

int main() {
    enum Akun {
        Dosen,
        Mahasiswa
    };

    cout << "Pilih jenis akun:" << endl;
    cout << "1. Dosen" << endl;
    cout << "2. Mahasiswa" << endl;
    cout << "Masukkan pilihan Anda (1/2): ";

    int pilihan;
    cin >> pilihan;

    Akun akun_pengguna;

    if (pilihan == 1) {
        akun_pengguna = Dosen;
    } else if (pilihan == 2) {
        akun_pengguna = Mahasiswa;
    } else {
        cout << "Pilihan tidak valid!" << endl;
        return 0;
    }

    cout << endl;
    cout << "tipe data enum (enumeration)" << endl;
    cout << "-----------------------------" << endl;

    if (akun_pengguna == Dosen) {
        cout << "Anda memilih akun: Dosen" << endl;
    } else if (akun_pengguna == Mahasiswa) {
        cout << "Anda memilih akun: Mahasiswa" << endl;
    }

    return 0;
}