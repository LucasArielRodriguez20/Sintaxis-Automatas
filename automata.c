#include<stdlib.h> //system()
#include "automata.h"

int palabraPertenece(char *  palabra)
{
    int i=0;
    while(palabra[i]!='\n')
        if(isdigit(palabra[i]) ||
                palabra[i]=='+'||
                palabra[i]=='-'||
                palabra[i]=='*'||
                palabra[i]=='/')
            i++;
        else
            return 0;
    return 1;
}
int esPalabra(char*palabra)//cambio para decimales 
{
    int estadoFinal = automata(palabra);
    if(estadoFinal == 1 || estadoFinal == 3)
        return 1;
    else
        if(estadoFinal == 4)
            return 1;
        else
            if(estadoFinal == 6)
                return 1;
    return 0;
}

//Devuelve el estado final
int automata(char*palabra){
    int tt[8][6]={{3,1,1,7,7,2},
                  {1,1,1,7,7,7},
                  {7,1,1,7,7,7},
                  {4,4,7,7,5,7},
                  {4,4,7,7,7,7},
                  {6,6,6,6,7,7},
                  {6,6,6,6,7,7},
                  {7,7,7,7,7,7}};
    int estado =0;
    int i=0;
    while(palabra[i]!='\0'&& estado!=7) {
        estado=tt[estado][columna(palabra[i],estado)];
        i++;
    }
    return estado;
}

int automataAritmetico(int c,int estado)
{
    int tt[2][2]={{1,0},{0,0}};
    return tt[estado][columnaAritmetica(c)];
}

