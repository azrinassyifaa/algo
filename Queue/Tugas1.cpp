#include <iostream>
using namespace std;

const int MAX = 10;   // kapasitas queue

// Struktur Queue
struct Queue {
    int data[MAX];
    int front;
    int rear;
};

// Inisialisasi queue
void init(Queue &q) {
    q.front = -1;
    q.rear = -1;
}

// Mengecek apakah kosong
bool isEmpty(Queue q) {
    return (q.front == -1 && q.rear == -1);
}

// Mengecek apakah penuh
bool isFull(Queue q) {
    return (q.rear == MAX - 1);
}

// Menambah elemen ke queue
void enqueue(Queue &q, int value) {
    if (isFull(q)) {
        cout << "Queue penuh! Tidak dapat menambah data.\n";
        return;
    }
    if (isEmpty(q)) {
        q.front = q.rear = 0;
    } else {
        q.rear++;
    }
    q.data[q.rear] = value;
    cout << "Berhasil menambahkan " << value << " ke queue.\n";
}

// Menghapus elemen dari queue
void dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue kosong! Tidak ada data yang dihapus.\n";
        return;
    }
    cout << "Menghapus data: " << q.data[q.front] << endl;

    if (q.front == q.rear) {
        // tinggal satu elemen → reset queue
        q.front = q.rear = -1;
    } else {
        q.front++;
    }
}

// Menampilkan isi queue
void display(Queue q) {
    if (isEmpty(q)) {
        cout << "Queue kosong!\n";
        return;
    }
    cout << "Isi Queue: ";
    for (int i = q.front; i <= q.rear; i++) {
        cout << q.data[i] << " ";
    }
    cout << endl;
}

// Menu utama
int main() {
    Queue q;
    init(q);

    int pilihan, nilai;

    do {
        cout << "\n=== PROGRAM QUEUE MENGGUNAKAN ARRAY ===\n";
        cout << "1. Enqueue (Tambah Data)\n";
        cout << "2. Dequeue (Hapus Data)\n";
        cout << "3. Tampilkan Queue\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                enqueue(q, nilai);
                break;

            case 2:
                dequeue(q);
                break;

            case 3:
                display(q);
                break;

            case 4:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 4);

    return 0;
}