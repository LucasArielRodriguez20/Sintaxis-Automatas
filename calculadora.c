#include <stdio.h>
#include<stdlib.h> //system()
#include <ctype.h> //isdigit()
#include "stack.h"//pop(),push()....
#include "verificacion.h"
#include "./automata/automata.h"

int numeroADecimal(ptrNodoN *,ptrNodo *);
void infijaApostfija(ptrNodo *);
int charAInt(char);

int main()
{
    struct NodoN * stack=NULL;
    struct Nodo * pilaPolaca=NULL;
    int c=0;
    double top=0;
    printf("\n Ingrese una expresion aritmetica del modo '1*2+5/5' \nActualmente la calculadora solo admite * / - + como operandos \n");
    if(!verificacion())
    {
        system("pause");
        return 0;
    }
        
    printf("    La expresion es valida \n");
    infijaApostfija(&pilaPolaca);
    ///comienzo calculadora
     while((c=numeroADecimal(&stack,&pilaPolaca))!=EOF) 
    {
        switch(c)
        {
            case '+':
                pushN(&stack,(popN(&stack)+popN(&stack)));
                break;
            case '-':
                top=popN(&stack)*-1;
                pushN(&stack,(popN(&stack)+top));
                break;
            case '*':
                pushN(&stack,(popN(&stack)*popN(&stack)));
                break;
            case '/':
                top=popN(&stack);
                if(top!=0)
                {
                    pushN(&stack,(popN(&stack)/top));
                }
                else{
                    printf("Error division por 0\n");
                    system("pause");
                    return 0;
                }
                break;
            case '0':
                break;
            case ' ':
                break;
            case '\t':
                break;
            case '$':
                break;
            case '!':
                break;
            case '\n':
                printf("El resultado es %.2f \n",popN(&stack));
                system("pause");
                break;
            default:
                printf("Es un dato no valido %c \n",c);
                system("pause");
                return 0;
                break;
        }
    } 
    return 0;
}
void infijaApostfija(ptrNodo * pilaPolaca){
    int c=0,aux;
    struct Nodo * stack=NULL;
    struct Nodo * operadores=NULL;
    struct Nodo * auxPila=NULL;
     ///infija a postfija
    while((c=getchar())!='\n')//continuo mientras c no sea fin de archivo y sea diferente a salto de linea 
    {
    switch(c)
    {
        case '+':
            push(&stack,' ');
            if(operadores == NULL)//si la pila esta vacia agrego el operador 
                push(&operadores,c);
            else
            {
                if(operadores->valor =='*'|| operadores->valor =='/')
                {
                    //sino esta vacia y en la cima de la pila hay un * o una /
                    while(operadores)//vacio la pila de operadores
                        push(&stack,pop(&operadores));// los operadores van a la pila principal
                    push(&operadores,c);//por ultimo guardo el + en la pila secundaria
                }
                else
                {
                    //tengo en mi pila secundaria un + o -
                    push(&stack,pop(&operadores));//extraigo el operador de mi pila secundaria y lo guardo en la principal
                    push(&operadores,c);//por ultimo guardo el + en la pila secundaria
                } 
            }
            break;
        case '-':
            push(&stack,' ');
        //mismo procedimiento para el -
            if(operadores == NULL)
                push(&operadores,c);
            else
            {
                if(operadores->valor =='*'|| operadores->valor =='/')
                {
                    while(operadores)
                    {
                        push(&stack,pop(&operadores));
                    }
                    push(&operadores,c);
                }
                else
                {
                    push(&stack,pop(&operadores));
                    push(&operadores,c);
                } 
            }
            break;
        case '*':
            push(&stack,' ');
            if(operadores == NULL)//si la pila esta vacia agrego el operador 
                push(&operadores,c);
            else
            {
                if(operadores->valor =='/'||operadores->valor =='*')
                {
                    //tengo en mi pila secundaria un * o /
                    push(&stack,pop(&operadores));//extraigo el de la pila secundaria y lo coloco en la principal
                    push(&operadores,c);//guardo el * en la pila secundaria
                }
                else
                    //tengo en mi pila secundaria un + o -
                    push(&operadores,c);//guardo el * en la pila secundaria
            }
            break;
        case '/':
            push(&stack,' ');//separar numeros con operadores
            if(operadores == NULL)
                push(&operadores,c);
            else
            {
                if(operadores->valor =='*'||operadores->valor =='/')
                {
                    push(&stack,pop(&operadores));
                    push(&operadores,c);
                }
                else
                    push(&operadores,c);
            }
            break;
        case'\n'://ignoro saltos de linea
            break;
        case'\t'://ignoro tabulaciones
            break;
        case' '://ignoro espacios
            break;
        default:
            push(&stack,c);//guardo un numero en la pila principal
            break;
        }      
    }
    while(operadores)// si queda algun operador en mi pila secundaria lo extraigo
        push(&stack,pop(&operadores));
    ///pila cargada con la expresion 
    push(&stack,'\n');
    while(stack)
        push(pilaPolaca,pop(&stack));//devuelvo la exprecion en polaca inversa a la entrada 
}

int numeroADecimal(ptrNodoN * stack,ptrNodo *pilaPolaca)
{
    int c=0,contador=0,contadorFraccionario=0;
    double sum=0.0;
    double numero[1000],fraccion[1000];//el numero en su parte entera y en su parte fraccionaria
    if (isdigit(c=pop(pilaPolaca)))
    {
        //decimal
        //mismo procedimiento para el decimal solo que cambia el uso de pow , en este caso se utiliza para formar la parte fraccionaria
        while (isdigit(c))
        {
            sum*=10;
            sum+=charAInt(c);
            c=pop(pilaPolaca);
        }
        contador--;
        for(int i=0;contador>=0;i++)
        {
            sum*=10;
            sum+= numero[i];
            contador--;
        }
        pushN(stack,sum);
        sum=0;
        contador=0;
        contadorFraccionario=0;
        push(pilaPolaca,c);
        return '0';
    }
    else
        return c;//devuelvo el operador o espacio o tabulacion 
}

// PUNTO 2
int charAInt(char c){
    return c - '0';
}