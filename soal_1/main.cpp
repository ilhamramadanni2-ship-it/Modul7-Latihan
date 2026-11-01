#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    Stack S;
    createStack(S);
    int pilihan, val;
    bool status;

    do {
        cout << "\n=== MENU STACK ARRAY ===\n";
        cout << "1. Push\n2. Pop\n3. Tampilkan\n4. Balik Stack\n5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: "; cin >> val;
                if (push(S, val)) cout << "Berhasil push.\n";
                else cout << "Gagal! Stack penuh.\n";
                break;
            case 2:
                if (pop(S, val)) cout << "Berhasil pop nilai: " << val << endl;
                else cout << "Gagal! Stack kosong.\n";
                break;
            case 3:
                printInfo(S);
                break;
            case 4:
                balikStack(S);
                cout << "Stack berhasil dibalik.\n";
                break;
            case 5:
                cout << "Keluar program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 5);

    return 0;
}