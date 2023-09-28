#include "columnas.h"
int isAToF(int c){
    if(c>='A'&&c<='F')
    return 1;
    else
    return 0;
}
int columna(int c,int estado)
{
    switch (estado)
    {
    case 0:
        if(c=='0')
            return 3;
        else
            if(isdigit(c))
                return 1;
            else
                if(c=='+'||c=='-')
                    return 2;
                else
                    return 7;
        break;
    case 1:
        if(isdigit(c))
            return 1;
        else
            return 7;
        break;
    case 2:
        if(isdigit(c))
            return 1;
        else
            return 7;
        break;
    case 3:
        if(c>='0' && c<='7')
            return 4;
        else
            if(c=='x')
                return 5;
            else
                return 7;
        break;
    case 4:
        if(c>='0' && c<='7')
            return 4;
        else
            return 7;
        break;
    case 5:
        if(isdigit(c) || isAToF(c))
            return 6;
        else
            return 7;
        break;
    case 6:
        if(isdigit(c) || isAToF(c))
            return 6;
        else
            return 7;
        break;
    default:
        return 7;
        break;
    }
}