#include <iostream>
using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    float ipk;
}; 

void isiDataMahasiswa(Mahasiswa &mhs) {
    cout << "Masukkan NIM: ";
    getline(cin, mhs.nim);

    cout << "Masukkan Nama: ";
    getline(cin, mhs.nama);

    cout << "Masukkan IPK: ";
    cin >> mhs.ipk;

    cin.ignore();

}

int main(){
    Mahasiswa mhs1, mhs2, mhs3;

    cout << "======================================" << endl;
    cout << "Isi data Mahasiswa 1" << endl;
    isiDataMahasiswa(mhs1);
    cout << "======================================" << endl;
    cout << "Isi data Mahasiswa 2" << endl;
    isiDataMahasiswa(mhs2);
    cout << "======================================" << endl;
    cout << "Isi data Mahasiswa 3" << endl;
    isiDataMahasiswa(mhs3);

    cout << "======================================" << endl;
    cout << "Data Mahasiswa 1" << endl;
    cout << "NIM : " << mhs1.nim << endl;
    cout << "Nama: " << mhs1.nama << endl;
    cout << "IPK : " << mhs1.ipk << endl;

    cout << "======================================" << endl;
    cout << "Data Mahasiswa 2" << endl;
    cout << "NIM : " << mhs2.nim << endl;
    cout << "Nama: " << mhs2.nama << endl;
    cout << "IPK : " << mhs2.ipk << endl;

    cout << "======================================" << endl;
    cout << "Data Mahasiswa 3" << endl;
    cout << "NIM : " << mhs3.nim << endl;
    cout << "Nama: " << mhs3.nama << endl;
    cout << "IPK : " << mhs3.ipk << endl;

    return 0;

}