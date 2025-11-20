#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    Mahasiswa mhs[3];

    for (int i = 0; i < 3; i++) {
        cout << "Masukkan data mahasiswa ke-" << i+1 << endl;
        cout << "Nama : "; getline(cin, mhs[i].nama);
        cout << "NIM  : "; getline(cin, mhs[i].nim);
        cout << "IPK  : "; cin >> mhs[i].ipk;
        cin.ignore();
        cout << endl;
    }

    cout << "\n=====================================\n";
    cout << "No\tNama\t\tNIM\t\tIPK\n";
    cout << "=====================================\n";
    for (int i = 0; i < 3; i++) {
        cout << i+1 << "\t" << mhs[i].nama << "\t" << mhs[i].nim << "\t" << mhs[i].ipk << endl;
    }
}