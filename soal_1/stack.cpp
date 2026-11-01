#include "stack.h"

void createStack(Stack &S) {
    S.Top = 0;
}

bool isEmpty(Stack S) {
    return S.Top == 0;
}

bool isFull(Stack S) {
    return S.Top == IDXMAX;
}

bool push(Stack &S, int x) {
    if (isFull(S)) {
        return false;
    } else {
        S.Top++;
        S.info[S.Top] = x;
        return true;
    }
}

bool pop(Stack &S, int &x) {
    if (isEmpty(S)) {
        return false;
    } else {
        x = S.info[S.Top];
        S.Top--;
        return true;
    }
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "(Stack Kosong)" << endl;
    } else {
        cout << "TOP: ";
        for (int i = S.Top; i >= 1; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    int val;
    
    // Pindahkan semua elemen ke stack bantu
    while (!isEmpty(S)) {
        pop(S, val);
        push(temp, val);
    }
    
    // Pindahkan kembali ke stack asli (terbalik)
    while (!isEmpty(temp)) {
        pop(temp, val);
        push(S, val);
    }
}