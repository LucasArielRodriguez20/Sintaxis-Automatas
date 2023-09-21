#include "columnas.h"
int columnaO(int c , int estado)
{
    if(estado == 0)
    {
        switch (c)
                {
                    case'0':
                        return 2;
                        break;
                    default:
                        return 0;
                        break;
                }
    }
    else
    {
        if(estado==1)
        {
            if(isdigit(c))
            {
                return 0;
            }
            switch (c)
                {
                    case',':
                        return 3;
                        break;
                    default:
                        return 1;
                        break;
                }
        }
        else
        {
            if(estado==2)
            {
                if(isdigit(c))
                {
                    if(c!=0)
                        return 1;
                    else
                        return 0;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                if(estado==3)
                {
                   if(isdigit(c))
                    {
                        return 0;
                     }
                    else
                    {
                        return 1;
                    }
                }
            }
        }
    }
    
}
int columnaH(int c , int estado)
{
    if(estado==0)
    {
        switch (c)
                {
                    case'0':
                        return 1;
                        break;
                    default:
                        return 0;
                        break;
                }
    }
    else
    {
        if(estado==1)
        {
            switch (c)
                    {
                    case'x':
                        return 3;
                        break;
                    default:
                        return 0;
                        break;
                    }
        }
        else
        {
            if(estado==2)
            {
                if(isdigit(c)||isAToF(c))
                 return 0;
                switch (c)
                {
                    case',':
                        return 2;
                        break;
                    default:
                        return 1;
                        break;
                }
            }
            else
            {
                if(estado==3)
                {
                    if(isdigit(c)||isAToF(c))
                    {
                        return 0;
                    }
                    else
                    {
                        return 1;
                    }
                }
            }
        }
    }
}
int isAToF(int c){
    if(c>=65&&c<=70)
    return 1;
    else
    return 0;
}
int columnaD(int c,int estado)
{
    if(estado==0)
    {
        if(isdigit(c))
        {
            if(c!=0)
                return 1;
        }
        switch (c)
                {
                    case'+':
                        return 4;
                        break;
                    case'-':
                        return 4;
                        break;
                    case'0':
                        return 2;
                        break;
                    default:
                        return 0;
                        break;
                }
    }
    else
    {
        if(estado==1)
        {
            if(isdigit(c))
            {
                if(c!=0)
                    return 1;
            }
            switch (c)
                {
                    case'0':
                        return 2;
                        break;
                    default:
                        return 0;
                        break;
                }
        }
        else
        {
            if(estado==2)
            {
                if(isdigit(c))
                {
                    return 0;
                }
                switch (c)
                    {
                        case'+':
                            return 4;
                            break;
                        case'-':
                            return 4;
                            break;
                        case',':
                            return 3;
                            break;
                        default:
                            return 1;
                            break;
                    }
            }
            else
            {
                if(estado==3)
                {
                    if(isdigit(c))
                    {
                        return 0;
                    }
                    else
                    {
                        return 1;
                    }
                }
                else
                {
                    if(estado==4)
                    {
                        switch (c)
                        {
                            case',':
                                return 3;
                                break;
                            default:
                                return 1;
                                break;
                        }
                    }
                }
            }
        }
    }
}