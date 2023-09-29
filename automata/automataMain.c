#include "automata.h"
#include "columnas.h"
#include <ctype.h> 
#include<stdio.h> 
#include<stdlib.h> //system()

#define MAX_LENGTH 1000

int esPalabraConstantesEnteras(char*,int *,int *,int *);

int main()
{
    char palabra[(MAX_LENGTH + 1)];
    int c=0,i=0,octal=0,decimal=0,hexa=0;
    printf("Ingrese su expresion de numeros intercalados con $ (Maximo %d caracteres por numero) \n", MAX_LENGTH);
    
    while(c!='\n')
    {
        i=0;

        //Lee una cadena
        c=getchar();
        while(c!='$'&& c!='\n')
        {
            palabra[i]=c;
            printf(" %c ",palabra[i]);
            i++;   
            c=getchar();
        }

        printf("    Cadena leida \n");

        if(i>MAX_LENGTH){
            printf("La cadena leida tiene más caracteres de lo permitido \n");
            break;
        }


        // Agrega el caracter de fin de cadena al final de la cadena leida
        palabra[i]='\0';

        if(cadenaPerteneceConstantesEnteras(palabra))
        {
            if(esPalabraConstantesEnteras(palabra,&octal,&decimal,&hexa))
            {
                printf("La palabra ingresada es correcta \n");
            }
            else
            {
                printf("La cadena ingresada no pertenece al lenguaje \n");
                break;
            }
        }
        else
        {
            printf("La cadena ingresada no esta compuesta por caracteres del alfabeto del lenguaje \n");
            break;
        }
    } 
    printf("Cantidad de octales %d \n",octal);
    printf("Cantidad de decimales %d \n",decimal);
    printf("Cantidad de hexadecimales %d \n",hexa);
    
    system("pause");
    return 0;
}

// Devuelve si es una palabra reconocida por el automata de constantes enteras y aumenta el contador acorde
int esPalabraConstantesEnteras(char*palabra,int *octal,int *decimal,int *hexa)
{
    int estadoFinal = automataConstantesEnteras(palabra);
    if(esDecimal(estadoFinal)){
        *decimal+=1;
        return 1;
    }
    if(esOctal(estadoFinal)){
        *octal+=1;
        return 1;
    }
    if(esHexa(estadoFinal)){
        *hexa+=1;
        return 1;
    }
    return 0;
}