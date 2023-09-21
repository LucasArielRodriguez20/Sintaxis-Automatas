#include "stack.h"
void push(ptrNodo * stack,int dato)
{
    ptrNodo p=(ptrNodo)malloc(sizeof(nodo));//new nodo
    p->valor=dato;
    p->sgte=*stack;//desreferencio para acceder a la pila
    *stack=p;
}

int pop(ptrNodo* stack)
{
    int x=(*stack)->valor;
    ptrNodo aux=(*stack);
    *stack=aux->sgte;
    free(aux);
    return x;
}

void pushN(ptrNodoN* stack,double dato)
{
    ptrNodoN p=(ptrNodoN)malloc(sizeof(nodoN));//new nodo
    p->valor=dato;
    p->sgte=*stack;//desreferencio para acceder a la pila
    *stack=p;
}

double popN(ptrNodoN* stack)
{
    double x=(*stack)->valor;
    ptrNodoN aux=(*stack);
    *stack=aux->sgte;
    free(aux);
    return x;
}