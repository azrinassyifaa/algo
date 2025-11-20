#include <iostream>
using namespace std;

int main() {
    int umur;

    cout << "Masukkan umur: ";
    cin >> umur;

    if (umur >= 18) {
        cout << "Dewasa" << endl;
    } else {
        cout << "Belum Dewasa" << endl;
    }

    return 0;
}