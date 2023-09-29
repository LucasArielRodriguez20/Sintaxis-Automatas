#include "automata.h"

int verificacion(){
    int c,i=0,j=0,estado=0,top=0;
    char expresionAritmetica[1000];
    char numero[10];
    while((c=getchar())!='\n')
    {
        if(c!=32||c!=9)//ignoramos esapcios y tabs de la expresion
        {
            expresionAritmetica[i]=c;
            i++;
        }
        
    }
    //obtengo la expresion en su totalidad
    ungetc(c,stdin);
    expresionAritmetica[i]='\n';
    top=i-1;
    if(!palabraPertenece(expresionAritmetica))//verificamos la expresion leida
    {
        printf("hay un caracter incorrecto en la expresion \n");
        return 0;
    }
    //si esta todo correcto seguimos analizando 
    i=0;
    while(expresionAritmetica[i]!='\n')//mientras no se acabe la expresion
    {
        //encontramos un operador o un numero en la expresion
        if(isdigit(expresionAritmetica[i]))///es un numero 
        {
            while(isdigit(expresionAritmetica[i]))//recolecto los numeros de la expresion 
            {
                numero[j]=expresionAritmetica[i];
                j+=1;
                i+=1;
            }
            if(esPalabra(numero))//verifico que ese numero es realmente un decimal 
            {
                estado= automataAritmetico(1,estado);//avanzo en mi automata
            } 
            else
            {
                printf("ERROR ingreso de numero invalido\n");
                return 0;
            }
            j=0;
        }
        else//no es un numero entonces es un operador 
        {
            estado=automataAritmetico(0,estado);
            i++;
        }
    }
    if(estado == 1)
    {
        while (top!=-1)//devulevo la entrada en el mismo sentido que la ingrese para no afectar la precedencia
        {
           ungetc(expresionAritmetica[top],stdin);
           top--;
        }
        return 1;
    }
    else 
    return 0;
}