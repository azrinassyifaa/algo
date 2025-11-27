#include <iostream>
using namespace std;

#define MAX 5

int main() {
    int queueArr[MAX];
    int front = 0, rear = -1, count = 0;

    cout << "=== SIMULASI CIRCULAR QUEUE ===\n\n";

    // 1. Mengisi queue hingga penuh
    cout << "1) Mengisi queue sampai penuh...\n";
    for(int i = 1; i <= MAX; i++) {
        rear = (rear + 1) % MAX;
        queueArr[rear] = i * 10;   // contoh data: 10,20,30,40,50
        count++;
        cout << "Enqueue: " << queueArr[rear] << endl;
    }

    cout << "\nIsi queue saat penuh: ";
    for(int i = 0; i < MAX; i++) cout << queueArr[i] << " ";
    cout << "\n\n";


    // 2. Menghapus 3 elemen
    cout << "2) Menghapus 3 elemen...\n";
    for(int i = 0; i < 3; i++) {
        cout << "Dequeue: " << queueArr[front] << endl;
        front = (front + 1) % MAX;
        count--;
    }

    cout << "\nIsi queue setelah hapus 3 elemen (secara memori): ";
    for(int i = 0; i < MAX; i++) cout << queueArr[i] << " ";
    cout << "\n\n";


    // 3. Mengisi 2 elemen baru
    cout << "3) Menambah 2 elemen baru...\n";
    int newData1 = 99, newData2 = 88;

    rear = (rear + 1) % MAX;
    queueArr[rear] = newData1;
    count++;
    cout << "Enqueue: " << newData1 << endl;

    rear = (rear + 1) % MAX;
    queueArr[rear] = newData2;
    count++;
    cout << "Enqueue: " << newData2 << endl;

    cout << "\n";

    // 4. Menampilkan posisi front dan rear
    cout << "4) Posisi Front dan Rear:\n";
    cout << "Front index: " << front << endl;
    cout << "Rear index : " << rear << endl << endl;


    // 5. Menampilkan isi queue secara circular (menggunakan modulo)
    cout << "5) Isi queue sesuai urutan (circular): ";
    int index = front;
    for(int i = 0; i < count; i++) {
        cout << queueArr[index] << " ";
        index = (index + 1) % MAX;
    }

    cout << "\n\n=== Selesai ===\n";

    return 0;
}