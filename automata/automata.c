#include<stdio.h> 
#include<stdlib.h> //system()
#include <ctype.h> //isdigit()
#include "columnas.h"
#include "automata.h"

// Devuelve si la cadena esta compuesta por caracteres del alfabeto de constantes enteras
int cadenaPerteneceConstantesEnteras(char *  palabra)
{
    int i=0;
    while(palabra[i]!='\0')
    {
        if(isdigit(palabra[i]) ||
                palabra[i]=='+'||
                palabra[i]=='-'||
                palabra[i]=='A'||
                palabra[i]=='x'||
                palabra[i]=='B'||
                palabra[i]=='C'||
                palabra[i]=='D'||
                palabra[i]=='E'||
                palabra[i]=='F'||
                palabra[i]=='$')
        {
            i++;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

// Devuelve si la cadena esta compuesta por caracteres del alfabeto de operadores aritmeticos
int cadenaPerteneceCalculadora(char * palabra){
    int i=0;
    while(palabra[i]!='\0' && palabra[i]!='\n')
    {
        printf("%c", palabra[i]);
        if(isdigit(palabra[i]) ||
            palabra[i]=='+'||
            palabra[i]=='-'||
            palabra[i]=='*'||
            palabra[i]=='/')
        {
            i++;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

// Devuelve si una cadena pertenece al lenguaje de los decimales
int esPalabraDecimal(char*palabra){
    return esDecimal(automataConstantesEnteras(palabra));
}

//Devuelve si el estado final corresponde a un numero decimal
int esDecimal(int estadoFinal){
    return estadoFinal == 1 || estadoFinal == 3;
}

//Devuelve si el estado final corresponde a un numero hexadecimal
int esHexa(int estadoFinal){
    return estadoFinal == 4;
}

//Devuelve si el estado final corresponde a un numero octal
int esOctal(int estadoFinal){
    return estadoFinal == 6;
}

//Devuelve el estado final del automata de constantes enteras
int automataConstantesEnteras(char*palabra){
    int tt[8][6]={{3,1,1,7,7,2},
                  {1,1,1,7,7,7},
                  {7,1,1,7,7,7},
                  {4,4,7,7,5,7},
                  {4,4,7,7,7,7},
                  {6,6,6,6,7,7},
                  {6,6,6,6,7,7},
                  {7,7,7,7,7,7}};
    int estado = 0;
    int i=0 ;
    while(palabra[i]!='\0'&& estado!=7) {
        estado=tt[estado][columna(palabra[i])];
        i++;
    }
    return estado;
}