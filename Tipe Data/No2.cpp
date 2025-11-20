#include <iostream>
using namespace std;

int main() {
    int a, b;
    double c;

    cout << "Masukkan dua bilangan bulat: ";
    cin >> a >> b;
    cout << "Masukkan satu bilangan desimal: ";
    cin >> c;

    cout << "Hasil penjumlahan: " << a + b + c << endl;
    cout << "Hasil pengurangan: " << a - b - c << endl;
    cout << "Hasil perkalian: " << a * b * c << endl;
    cout << "Hasil pembagian: " << (a / c) << endl;

    return 0;
}