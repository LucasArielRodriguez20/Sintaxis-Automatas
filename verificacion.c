#include "./automata/automata.h"
#include <stdio.h>

int verificacion(){
    int c,i=0,estado=0,top=0;
    int ultimoFueNumero = 0;
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
    if(!cadenaPerteneceCalculadora(expresionAritmetica))//verificamos la expresion leida
    {
        printf("hay un caracter incorrecto en la expresion \n");
        return 0;
    }
    //si esta todo correcto seguimos analizando 
    i=0;
    while(expresionAritmetica[i]!='\n')//mientras no se acabe la expresion
    {
        //encontramos un operador o un numero en la expresion
        if(isdigit(expresionAritmetica[i]) && !ultimoFueNumero)///es un numero 
        {
            int j = 0;
            while(isdigit(expresionAritmetica[i]))//recolecto los numeros de la expresion 
            {
                numero[j]=expresionAritmetica[i];
                j+=1;
                i+=1;
            }
            if(esPalabraDecimal(numero))//verifico que ese numero es realmente un decimal 
            {
                ultimoFueNumero = 1;// Dejo la marca que el ultimo fue un numero, por lo que el siguiente debe ser un operador
            } 
            else
            {
                printf("ERROR ingreso de numero invalido\n");
                return 0;
            }
        }
        else if(ultimoFueNumero)//no es un numero entonces es un operador 
        {
            ultimoFueNumero = 0;
            i++;
        }
        else{
            printf("ERROR expresion invalida\n");
            return 0;
        }
    }
    if(ultimoFueNumero == 1)
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