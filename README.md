# Sintaxis y Semántica de los lenguajes: Trabajo Practico "Autómatas"

# Calculadora en C

Este repositorio contiene una calculadora basada en c que es posible de realizar multiplicaciones, divisiones, sumas y restas entre números decimales, hexadecimales y octales. Pero por el momento no puede realizar operaciones de ningún tipo con números negativos 


# Contenido del repositorio

El repositorio contiene un archivo Makefile para agilizar la compilación del código , un archivo calculadora.c , un archivo stack.c, un archivo stack.h y por ultimo un manual de usuario con las explicaciones de uso.

## calculadora.c
Esta dividido en dos partes, primero una verificación de la expresión introducida mediante un autómata que si acepta la expresión comienza a transformarla de infija a postfija o polaca inversa. En la segunda parte comenzamos  tomando la expresión previamente convertida y por medio de un switch vamos introduciendo los números uno a uno en la pila y cuándo encontramos un operador efectuamos la operación y devolvemos ala pila el resultado de la misma. Finalmente mostramos el resultado de la operación que queda alojado en la cima de la pila.

## stack.c
En este archivo agrupamos las funciones y las estructuras que nos permiten manipular la pila , en este programa se utilizan dos estructuras de pila una que guarda solo datos del tipo char y otra que utiliza datos de tipo double (para realizar operaciones con números fraccionarios y tener una mayor precisión).Por el lado de las funciones tenemos pop() que nos permite sacar el tope de la pila y push que nos permite guardar en la pila, a su vez tenemos sus versiones para double como popN() y pushN(), que realizan las mismas funciones pero en este caso solo para datos de tipo double.

## stack.h
En este archivo agrupamos las firmas de las funciones y las estructuras que nos permiten manipular la pila.



# Información académica:

  

- Curso: K2055

- Año de cursada: 2023

- Modalidad : Anual

- Facultad: Universidad Tecnológica Nacional FRBA

  

# Información de lo integrantes

- Nombre:

- Rodríguez Lucas Ariel

- Golato Barcia Ivan Nahuel

- Sayago Pablo

- Rabahia Maron Leonel

- Schinca Mauro

- Numero de Grupo: 30