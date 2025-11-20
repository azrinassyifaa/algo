#include <iostream>
using namespace std;

// Fungsi Bubble Sort
int bubbleSort(int arr[], int n) {
    int langkah = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            langkah++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return langkah;
}

// Fungsi Selection Sort
int selectionSort(int arr[], int n) {
    int langkah = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            langkah++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    return langkah;
}

// Fungsi untuk menampilkan array
void tampilArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int n = 10;
    int data[n], dataBubble[n], dataSelect[n];

    cout << "Masukkan " << n << " angka integer: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Data ke-" << i + 1 << ": ";
        cin >> data[i];
    }

    for (int i = 0; i < n; i++) {
        dataBubble[i] = data[i];
        dataSelect[i] = data[i];
    }

    cout << "\nData sebelum diurutkan: ";
    tampilArray(data, n);

    int langkahBubble = bubbleSort(dataBubble, n);
    cout << "\nHasil Bubble Sort (Ascending): ";
    tampilArray(dataBubble, n);
    cout << "Jumlah langkah/perbandingan Bubble Sort: " << langkahBubble << endl;

    int langkahSelect = selectionSort(dataSelect, n);
    cout << "\nHasil Selection Sort (Ascending): ";
    tampilArray(dataSelect, n);
    cout << "Jumlah langkah/perbandingan Selection Sort: " << langkahSelect << endl;

    cout << "\n=== Kesimpulan ===" << endl;
    if (langkahBubble > langkahSelect) {
        cout << "Selection Sort lebih efisien dibanding Bubble Sort." << endl;
    } else if (langkahBubble < langkahSelect) {
        cout << "Bubble Sort lebih efisien dibanding Selection Sort." << endl;
    } else {
        cout << "Keduanya memiliki efisiensi yang sama pada data ini." << endl;
    }

    return 0;
}
