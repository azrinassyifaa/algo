#include <iostream>
using namespace std;

int main() {
    int arr[7] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    bool found = false;

    cout << "Masukkan angka yang ingin dicari: ";
    cin >> target;

    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            cout << "Data ditemukan di indeks ke-" << mid << endl;
            found = true;
            break;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!found) {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}
