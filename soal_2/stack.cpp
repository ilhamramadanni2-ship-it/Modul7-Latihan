#include "stack.h"

void createStack(Stack &S) {
    S.Top = nullptr;
}

bool isEmpty(Stack S) {
    return S.Top == nullptr;
}

Node* alokasi(int x) {
    Node* p = new Node;
    p->info = x;
    p->next = nullptr;
    return p;
}

void dealokasi(Node* p) {
    delete p;
}

bool push(Stack &S, int x) {
    Node* p = alokasi(x);
    p->next = S.Top;
    S.Top = p;
    return true;
}

bool pop(Stack &S, int &x) {
    if (isEmpty(S)) {
        return false;
    } else {
        Node* p = S.Top;
        x = p->info;
        S.Top = p->next;
        p->next = nullptr;
        dealokasi(p);
        return true;
    }
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "(Stack Kosong)" << endl;
    } else {
        cout << "TOP: ";
        Node* p = S.Top;
        while (p != nullptr) {
            cout << p->info << " ";
            p = p->next;
        }
        cout << endl;
    }
}

void pushAscending(Stack &S, int x) {
    // Stack bantu untuk menampung sementara
    Stack temp;
    createStack(temp);
    int val;

    // Pindahkan elemen dari S ke temp jika nilainya lebih besar dari x
    while (!isEmpty(S) && S.Top->info > x) {
        pop(S, val);
        push(temp, val);
    }

    // Sisipkan nilai x
    push(S, x);

    // Kembalikan elemen dari temp ke S
    while (!isEmpty(temp)) {
        pop(temp, val);
        push(S, val);
    }
}

void clearStack(Stack &S) {
    int val;
    while (!isEmpty(S)) {
        pop(S, val);
    }
}