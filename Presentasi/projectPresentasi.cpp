#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> undoStack, redoStack;
    string text = "", input;

    while (true) {
        cout << "\nTeks saat ini: " << text << endl;
        cout << "[1] Ketik teks\n[2] Undo\n[3] Redo\n[4] Keluar\nPilih: ";
        int pilihan;
        cin >> pilihan;
        cin.ignore(); // mengabaikan newline

        if (pilihan == 1) {
            cout << "Masukkan teks tambahan: ";
            string tambahan;
            getline(cin, tambahan);
            undoStack.push(text);
            text += tambahan;
            while (!redoStack.empty()) redoStack.pop();
        }
        else if (pilihan == 2) {
            if (!undoStack.empty()) {
                redoStack.push(text);
                text = undoStack.top();
                undoStack.pop();
            } else cout << "Tidak ada yang bisa di-undo.\n";
        }
        else if (pilihan == 3) {
            if (!redoStack.empty()) {
                undoStack.push(text);
                text = redoStack.top();
                redoStack.pop();
            } else cout << "Tidak ada yang bisa di-redo.\n";
        }
        else if (pilihan == 4) break;
        else cout << "Pilihan tidak valid.\n";
    }

    return 0;
}
