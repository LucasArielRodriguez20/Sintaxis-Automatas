#include <stdio.h>
#include <ctype.h> //isdigit()
#include <math.h>//pow()
#include "stack.h"//pop(),push()....

int numeroADecimal(ptrNodoN *);
int pertenceAlAlfabeto(int);
void infijaApostfija();

int main()
{
    struct NodoN * stack=NULL;
    int c=0;
    double top=0;
    printf("\n ingrese una expresion aritmetica con espacios entre operadores y numeros \nactualmente la calculadora solo admite * / - + como operandos \n");
    //verificacionDeExpresion();
    infijaApostfija();
    ///comienzo calculadora
     while((c=numeroADecimal(&stack))!=EOF)
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
                    pushN(&stack,(popN(&stack)/top));
                else
                    printf("Error division por 0");
                break;
            case '0':
                break;
            case ' ':
                break;
            case '\t':
                break;
            case '$':
                break;
            case '\n':
                printf("el resultado es %.2f",popN(&stack));
                break;
            default:
                printf("es un dato no valido \n");
                return 0;
                break;
        }
    }
    return 0;
}
void infijaApostfija(){
    int c=0,aux;
    struct Nodo * stack=NULL;
    struct Nodo * operadores=NULL;
     ///infija a postfija
    while((c=getchar())!=EOF && c !='\n')//continuo mientras c no sea fin de archivo y sea diferente a salto de linea 
    {
        if(pertenceAlAlfabeto(c))//verifico que c sea parte de mi alfabeto 
        {
            switch(c)
            {
                case '+':
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
                case' ':
                    push(&stack,c);//guardo los espacios como caracter centinela
                    break; 
                default:
                    push(&stack,c);//guardo un numero en la pila principal
                    break;
            }      
        }
    }
    while(operadores)// si queda algun operador en mi pila secundaria lo extraigo
        push(&stack,pop(&operadores));
        
    ///pila cargada con la expresion 
    push(&stack,'\n');//agrego un fin de exprecion con el salto de linea
    while(stack)
        ungetc(pop(&stack),stdin);//devuelvo la exprecion en polaca inversa a la entrada 
}

int pertenceAlAlfabeto(int c)
{
    //verificamos que c sea un numero[0-9]o una letra mayuscula[A-F] o un espacio o un salto de linea
    if(c>=45 && c<=57||c>=40 && c<=43||c==32 || c=='\n'|| c=='x')
        return 1;
    else{
        printf("\n error %c no pertenece al alfabeto",c);
        return 0;
    }     
}

int numeroADecimal(ptrNodoN * stack)
{
    int c=0,contador=0,contadorFraccionario=0;
    double sum=0.0;
    double numero[1000],fraccion[1000];//el numero en su parte entera y en su parte fraccionaria
    if (isdigit(c=getchar()))
    {
        if(c=='0')
        {
            c=getchar();//leo el siguiente 
            if(c=='x')
            {
                //hexa
                c=getchar();
                while (isdigit(c)||(c>=65&&c<=70))//mientras sea un digito o una letra [A-F]
                {
                    if((c>=65&&c<=70))//es una letra [A-F]
                    {
                        numero[contador]=c-48-7;
                        contador++;
                        c=getchar();
                    }
                    else
                    {
                        // es un digito
                        numero[contador]=(c-48);
                        contador++;
                        c=getchar();
                    }
                }
                contador--;
                for(int i=0;contador>=0;i++)
                {
                    sum+= (numero[contador]*pow(16,i));//convierto la parte entera en un decimal
                    contador--;
                }
                
                if(c == ','||c =='.')//encuentro una coma o punto para la parte fraccionaria
                {
                    c=getchar();
                    while (isdigit(c))
                    {
                        if((c>=65&&c<=70))//es una letra [A-F]
                        {
                            numero[contadorFraccionario]=c-48-7;
                            contadorFraccionario++;
                            c=getchar();
                        }
                        else
                        {
                            // es un digito
                            numero[contadorFraccionario]=(c-48);
                            contadorFraccionario++;
                            c=getchar();
                        }
                    }
                    contadorFraccionario--;
                    for(int i=((contadorFraccionario+1)*-1);contadorFraccionario>=0;i++)
                    {
                        //convierto la parte fraccionaria  en un decimal y la agrego al numero que ya cargue su parte entera
                        sum+= (fraccion[contadorFraccionario]*pow(16,i));
                        contadorFraccionario--;
                    }
                }
                pushN(stack,sum);//guardo el numero en la pila final
                sum=0;
                contador=0;
                contadorFraccionario=0;
                ungetc(c,stdin);//devuelvo el caracter que no es un digito del ultimo while
                return 48;
            }
            else
            {
                //octal
                //mismo procedimiento para el octal solo que cambia el primer parametro de pow en un 8
                while (isdigit(c))
                {
                    numero[contador]=(c-48);
                    contador++;
                    c=getchar();
                }
                contador--;
                for(int i=0;contador>=0;i++)
                {
                    sum+= (numero[contador]*pow(8,i));
                    contador--;
                }
                
                if(c == ','||c =='.')
                {
                    c=getchar();
                    while (isdigit(c))
                    {
                        fraccion[contadorFraccionario]=(c-48);
                        contadorFraccionario++;
                        c=getchar();
                    }
                    contadorFraccionario--;
                    for(int i=((contadorFraccionario+1)*-1);contadorFraccionario>=0;i++)
                    {
                        sum+= (fraccion[contadorFraccionario]*pow(8,i));
                        contadorFraccionario--;
                    }
                }
                pushN(stack,sum);
                sum=0;
                contador=0;
                contadorFraccionario=0;
                ungetc(c,stdin);
                return 48;
            }
        }
        else
        {
            //decimal
            //mismo procedimiento para el decimal solo que cambia el uso de pow , en este caso se utiliza para formar la parte fraccionaria
            while (isdigit(c))
                {
                    numero[contador]=(c-48);
                    contador++;
                    c=getchar();
                }
                contador--;
                for(int i=0;contador>=0;i++)
                {
                    sum*=10;
                    sum+= numero[i];
                    contador--;
                }
                
                if(c == ','||c =='.')
                {
                    c=getchar();
                    while (isdigit(c))
                    {
                        fraccion[contadorFraccionario]=(c-48);
                        contadorFraccionario++;
                        c=getchar();
                    }
                    contadorFraccionario--;
                    for(int i=0;contadorFraccionario>=i;i++)
                    {
                        sum+= (fraccion[i]/pow(10,(i+1)));
                    }
                }
                pushN(stack,sum);
                sum=0;
                contador=0;
                contadorFraccionario=0;
                ungetc(c,stdin);
                return 48;
        }
    }
    else
    return c;//devuelvo el operador o espacio o tabulacion 
}