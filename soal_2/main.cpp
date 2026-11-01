#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    Stack S;
    createStack(S);
    int pilihan, val;

    do {
        cout << "\n=== MENU STACK POINTER ===\n";
        cout << "1. Tambah Terurut (Ascending)\n2. Pop\n3. Tampilkan\n4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: "; cin >> val;
                pushAscending(S, val);
                cout << "Berhasil ditambahkan secara terurut.\n";
                break;
            case 2:
                if (pop(S, val)) cout << "Berhasil pop nilai: " << val << endl;
                else cout << "Gagal! Stack kosong.\n";
                break;
            case 3:
                printInfo(S);
                break;
            case 4:
                clearStack(S);
                cout << "Keluar program. Memori dibersihkan.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 4);

    return 0;
}