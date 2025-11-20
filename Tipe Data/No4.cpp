#include <iostream>
using namespace std;

int main() {
    int angka;
    bool genap; 

    cout << "Masukkan angka: ";
    cin >> angka;

    genap = (angka % 2 == 0);

    cout << "Apakah genap? ";

    if (genap)
        cout << "true";
    else
        cout << "false";

    cout << endl;

    return 0;
}