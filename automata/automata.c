#include<stdio.h>
#include "columnas.h"
int palabraPertenece(char *  );
int esPalabra(char*,int* ,int* ,int* );

int main()
{
    char palabra[1000];
    int c,i=0,octal=0,decimal=0,hexa=0;
    printf("ingrese su exprecion de numeros intercalados con $\n");
    while((c=getchar())!=EOF)
    {
        if(c == '$')
        {
            c=getchar();
            while(c!='$'&& c!='\n'&& c!=EOF)
            {
                palabra[i]=c;
                printf(" %c ",palabra[i]);
                i++;   
                c=getchar();
            }
            if(c == '$')
                ungetc(c,stdin);
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
                palabra[i]==','||
                palabra[i]=='A'||
                palabra[i]=='x'||
                palabra[i]=='B'||
                palabra[i]=='C'||
                palabra[i]=='D'||
                palabra[i]=='E'||
                palabra[i]=='F'||
                palabra[i]=='%')
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
    int tt[5][5]={{5,2,4,5,1},
                  {5,2,4,5,5},
                  {2,5,5,3,5},
                  {3,5,5,5,5},
                  {5,5,5,3,5}
    };
    int ttO[4][4]={{4,4,2,4},
                  {1,4,4,3},
                  {4,1,4,4},
                  {3,4,4,4}
    };
    int ttH[4][4]={{4,1,4,4},
                  {4,4,4,2},
                  {2,4,3,4},
                  {3,4,4,4}
    };
    int estado =0;
    int i=0;
    if(palabra[i]== '0')
    {
        i++;
        if(palabra[i]=='x')
        {
            i=0;
            //hexa
             while(palabra[i]!='\0'&& estado!=4)
            {
                estado=ttH[estado][columnaH(palabra[i],estado)];
                i++;
            }

            if(estado==2||estado==3)
            {
              *hexa+=1;
              return 1;  
            }
            else
            return 0;
        }
        else
        {
            i=0;
            //octal
             while(palabra[i]!='\0'&& estado!=4)
            {
                estado=ttO[estado][columnaO(palabra[i],estado)];
                i++;
            }

            if(estado==2||estado==1||estado==3)
            {
                *octal+=1;
                return 1;
            }
            else
            return 0;
        }
    }
    else
    {
        while(palabra[i]!='\0'&& estado!=5)
        {
            estado=tt[estado][columnaD(palabra[i],estado)];
            i++;
        }

        if(estado==2||estado==3||estado==4)
        {
            *decimal+=1;
            return 1;
        }
        else
        return 0;
    }
}