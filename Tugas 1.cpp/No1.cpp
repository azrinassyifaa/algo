#include <iostream>
using namespace std;

int main() {
    int angka;
    cout << "Masukkan sebuah bilangan bulat: ";
    cin >> angka;

    if (angka % 2 == 0) {
        cout << "Bilangan Genap" << endl;
    } else {
        cout << "Bilangan Ganjil" << endl;
    }

    return 0;
}
