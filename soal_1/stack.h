#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

const int IDXMAX = 20;

struct Stack {
    int info[IDXMAX + 1]; // Indeks 1-20
    int Top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
bool push(Stack &S, int x);
bool pop(Stack &S, int &x);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif