#include <iostream>
using namespace std;

const int MAX = 10;

struct QueueChar {
    char data[MAX];
    int front;
    int rear;
};

void init(QueueChar &q) {
    q.front = q.rear = -1;
}

bool kosong(QueueChar q) {
    return (q.front == -1);
}

bool penuh(QueueChar q) {
    return (q.rear == MAX - 1);
}

void insert(QueueChar &q, char c) {
    if (penuh(q)) {
        cout << "Queue penuh!\n";
        return;
    }

    if (kosong(q)) {
        q.front = q.rear = 0;
    } else {
        q.rear++;
    }

    q.data[q.rear] = c;
    cout << "Data '" << c << "' berhasil ditambahkan.\n";
}

void hapus(QueueChar &q) {
    if (kosong(q)) {
        cout << "Queue kosong!\n";
        return;
    }

    cout << "Menghapus: " << q.data[q.front] << endl;

    if (q.front == q.rear) {
        q.front = q.rear = -1;
    } else {
        q.front++;
    }
}

void display(QueueChar q) {
    if (kosong(q)) {
        cout << "Queue kosong!\n";
        return;
    }

    cout << "Isi queue: ";
    for (int i = q.front; i <= q.rear; i++) {
        cout << q.data[i] << " ";
    }
    cout << endl;
}

int main() {
    QueueChar q;
    init(q);

    int pilihan;
    char inputChar;

    do {
        cout << "\n=== MENU QUEUE CHAR ===\n";
        cout << "1. Tambah data (insert)\n";
        cout << "2. Hapus data (hapus)\n";
        cout << "3. Tampilkan isi queue\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan karakter: ";
                cin >> inputChar;
                insert(q, inputChar);
                break;

            case 2:
                hapus(q);
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
