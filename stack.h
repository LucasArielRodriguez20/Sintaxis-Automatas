#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <stdlib.h>// free() malloc()

typedef struct Nodo{
    int valor;
    struct Nodo * sgte;
}nodo;

typedef struct NodoN{
    double valor;
    struct NodoN * sgte;
}nodoN;

typedef nodo* ptrNodo;//el equivalente a *& que seria **
typedef nodoN* ptrNodoN;

void push(ptrNodo * ,int );
int pop(ptrNodo* );
void pushN(ptrNodoN * ,double );
double popN(ptrNodoN* );
#endif