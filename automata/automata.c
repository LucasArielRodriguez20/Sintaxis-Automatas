#include<stdio.h> 
#include<stdlib.h> //system()
#include "columnas.h"
int palabraPertenece(char *  );
int esPalabra(char*,int* ,int* ,int* );
int automata(char*);

int main()
{
    char palabra[1000];
    int c=0,i=0,octal=0,decimal=0,hexa=0;
    printf("ingrese su expresion de numeros intercalados con $\n");
    
    while(c!='\n')
    {
        c=getchar();
            while(c!='$'&& c!='\n')
            {
                palabra[i]=c;
                printf(" %c ",palabra[i]);
                i++;   
                c=getchar();
            }
        palabra[i]='\0';
        i=0;
        printf("palabra leida \n");
        if(palabraPertenece(palabra))
        {
            if(esPalabra(palabra,&octal,&decimal,&hexa))
            {
                printf("la palabra ingresada es correcta \n");
            }
            else
            {
                printf("la palabra ingresada no es correcta \n");
                printf("cantidad de palabras octales %d \n",octal);
                printf("cantidad de palabras decimales %d \n",decimal);
                printf("cantidad de palabras hexadecimales %d \n",hexa);
                return 0;
            }
        }
        else
        {
            printf("la palabra no pertenece al lenguaje");
            return 0;
        }
    } 
    printf("cantidad de palabras octales %d \n",octal);
    printf("cantidad de palabras decimales %d \n",decimal);
    printf("cantidad de palabras hexadecimales %d \n",hexa);
    
    system("pause");
    return 0;
}
int palabraPertenece(char *  palabra)
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
int esPalabra(char*palabra,int *octal,int *decimal,int *hexa)
{
    int estadoFinal = automata(palabra);
    if(estadoFinal == 1 || estadoFinal == 3){
        *decimal+=1;
        return 1;
    }
    else{
        if(estadoFinal == 4){
            *octal+=1;
            return 1;
        }
        else{
            if(estadoFinal == 6){
                *hexa+=1;
                return 1;
            }
        }
    }
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