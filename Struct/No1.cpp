#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float nilai;

};

int main(){
    Mahasiswa mhs;
    
    cout << "=================================" <<endl;
    mhs.nim = "20250801081";
    mhs.nama = "Azrina syifa";
    mhs.nilai = 100;

    cout << "Nim: " << mhs.nim << endl;
    cout << "Nama: " << mhs.nama << endl;
    cout << "Nilai: " << mhs.nilai << endl;

    return 0;

}