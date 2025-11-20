#include <iostream>
using namespace std;

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

int insertionSort(int arr[], int n) {
    int langkah = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            langkah++;
        }
        arr[j + 1] = key;
        langkah++;
    }
    return langkah;
}

void tampilArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int n = 10;
    int data[n], dataBubble[n], dataInsert[n];

    cout << "Masukkan " << n << " angka integer: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Data ke-" << i + 1 << ": ";
        cin >> data[i];
    }

    for (int i = 0; i < n; i++) {
        dataBubble[i] = data[i];
        dataInsert[i] = data[i];
    }

    cout << "\nData sebelum diurutkan: ";
    tampilArray(data, n);

  
    int langkahBubble = bubbleSort(dataBubble, n);
    cout << "\nHasil Bubble Sort (Ascending): ";
    tampilArray(dataBubble, n);
    cout << "Jumlah langkah/perbandingan Bubble Sort: " << langkahBubble << endl;

    int langkahInsert = insertionSort(dataInsert, n);
    cout << "\nHasil Insertion Sort (Ascending): ";
    tampilArray(dataInsert, n);
    cout << "Jumlah langkah/perbandingan Insertion Sort: " << langkahInsert << endl;

    cout << "\n=== Kesimpulan ===" << endl;
    if (langkahBubble > langkahInsert) {
        cout << "Insertion Sort lebih efisien dibanding Bubble Sort." << endl;
    } else if (langkahBubble < langkahInsert) {
        cout << "Bubble Sort lebih efisien dibanding Insertion Sort." << endl;
    } else {
        cout << "Kedua algoritma memiliki efisiensi yang sama." << endl;
    }

    return 0;
}