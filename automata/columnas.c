#include "columnas.h"
#include<stdio.h> 

// Devuelve si c esta en el rango [A-F]
int isAToF(int c){
    if(c>='A'&&c<='F')
        return 1;
    else
        return 0;
}

// Dado un caracter devuelve cual es la columna que le corresponde en la tabla de transiciones del automata de constantes enteras
int columna(int c)
{
    if(c=='0')
        return 0;
    if(c>='1' && c<='7')
        return 1;
    if(c=='8' || c=='9')
        return 2;
    if(isAToF(c))
        return 3;
    if(c=='x')
        return 4;
    if(c=='-' || c=='+')
        return 5;
}