#include <iostream>
using namespace std;

int main() {
    char huruf;

    cout << "Masukkan satu huruf: ";
    cin >> huruf;

    cout << "Kode ASCII dari " << huruf << " adalah " << int(huruf) << endl;

    return 0;
}