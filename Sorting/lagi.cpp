#include <iostream>
using namespace std;

void tampilData(int data[], int n) {
    for (int i = 0; i < n; i++)
        cout << data[i] << " ";
    cout << endl;
}

int bubbleSort(int data[], int n) {
    int langkah = 0;
    int tempData[100];
    for (int i = 0; i < n; i++)
        tempData[i] = data[i];

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            langkah++;
            if (tempData[j] > tempData[j + 1]) {
                int temp = tempData[j];
                tempData[j] = tempData[j + 1];
                tempData[j + 1] = temp;
            }
        }
    }

    cout << "Hasil Bubble Sort (Ascending): ";
    tampilData(tempData, n);
    return langkah;
}

int selectionSort(int data[], int n) {
    int langkah = 0;
    int tempData[100];
    for (int i = 0; i < n; i++)
        tempData[i] = data[i];

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            langkah++;
            if (tempData[j] < tempData[minIndex])
                minIndex = j;
        }
        int temp = tempData[i];
        tempData[i] = tempData[minIndex];
        tempData[minIndex] = temp;
    }

    cout << "Hasil Selection Sort (Ascending): ";
    tampilData(tempData, n);
    return langkah;
}

int main() {
    int n;
    int data[100];

    cout << "Masukkan jumlah data: ";
    cin >> n;

    cout << "Masukkan " << n << " angka integer:\n";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    cout << "\nData sebelum diurutkan: ";
    tampilData(data, n);


    int langkahBubble = bubbleSort(data, n);

    int langkahSelection = selectionSort(data, n);

    cout << "\nJumlah langkah/perbandingan:\n";
    cout << "Bubble Sort     : " << langkahBubble << " langkah\n";
    cout << "Selection Sort  : " << langkahSelection << " langkah\n";

    cout << "\nKesimpulan:\n";
    if (langkahBubble < langkahSelection)
        cout << "Bubble Sort lebih efisien pada data ini.\n";
    else if (langkahBubble > langkahSelection)
        cout << "Selection Sort lebih efisien pada data ini.\n";
    else
        cout << "Kedua algoritma memiliki efisiensi yang sama pada data ini.\n";

    return 0;
}