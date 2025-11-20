#include <iostream>
using namespace std;

int main() {
    int arr[5] = {5, 10, 15, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 15;
    int result = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            result = i;
            break;
        }
    }

    if (result != -1) {
        cout << "Angka ditemukan di indeks ke-" << result <<endl;
     } else {
        cout << " Angka tidak ditemukan" << endl;
     }

     return 0;
 }
