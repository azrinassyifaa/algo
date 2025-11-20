#include <iostream>
#include <vector>

using namespace std;

void printData(const vector<int>& data) {
    for (int num : data) {
        cout << num << " ";
    }
    cout << endl;
}

int bubbleSort(vector<int>& data) {
    int n = data.size();
    int comparisons = 0;
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            comparisons++;
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
    return comparisons;
}

int selectionSort(vector<int>& data) {
    int n = data.size();
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }
        swap(data[i], data[minIndex]);
    }
    return comparisons;
}

int main() {
    vector<int> data;
    int n = 10;
    int input;

    cout << "Masukkan " << n << " angka integer:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> input;
        data.push_back(input);
    }

    cout << "\nData sebelum diurutkan: ";
    printData(data);

    vector<int> dataBubble = data;
    vector<int> dataSelection = data;

    int bubbleComparisons = bubbleSort(dataBubble);
    int selectionComparisons = selectionSort(dataSelection);

    cout << "\nHasil Bubble Sort (ascending): ";
    printData(dataBubble);
    cout << "Jumlah perbandingan Bubble Sort: " << bubbleComparisons << endl;

    cout << "\nHasil Selection Sort (ascending): ";
    printData(dataSelection);
    cout << "Jumlah perbandingan Selection Sort: " << selectionComparisons << endl;

    cout << "\nKesimpulan:" << endl;
    if (bubbleComparisons < selectionComparisons) {
        cout << "Bubble Sort melakukan lebih sedikit perbandingan dibanding Selection Sort." << endl;
    } else if (bubbleComparisons > selectionComparisons) {
        cout << "Selection Sort melakukan lebih sedikit perbandingan dibanding Bubble Sort." << endl;
    } else {
        cout << "Kedua algoritma melakukan jumlah perbandingan yang sama." << endl;
    }
    cout << "Optimasi pada Bubble Sort membuatnya lebih efisien pada data hampir terurut." << endl;

    return 0;
}
