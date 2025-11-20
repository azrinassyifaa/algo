#include <iostream>
using namespace std;

int main() {
    int a;
    int b;
    double c;


    cout << "Masukkan satu bilangan bulat: ";
    cin >> a;
    cout << "Masukkan satu bilangan bulat: ";
    cin >> b;
    cout << "Masukkan satu bilangan desimal: ";
    cin >> c;

    cout << "Hasil penjumlahan: " << a + b + c << endl;
    cout << "Hasil pengurangan: " << a - b - c << endl;
    cout << "Hasil perkalian: " << a * b * c << endl;
    cout << "Hasil pembagian: " << a / b / c << endl;

    return 0;

}