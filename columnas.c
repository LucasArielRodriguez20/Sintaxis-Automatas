#include "columnas.h"
int isAToF(int c){
    if(c>='A'&&c<='F')
        return 1;
    else
        return 0;
}
int columna(int c,int estado)
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
int columnaAritmetica(int c)
{
    if(c == 1)
        return 0;
    if(c == 0)
        return 1;
}