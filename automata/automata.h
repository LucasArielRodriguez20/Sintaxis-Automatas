#ifndef AUTOMATA_H_INCLUDED
#define AUTOMATA_H_INCLUDED
#include <ctype.h> //isdigit()
#include "columnas.h"
int cadenaPerteneceConstantesEnteras(char *  );
int cadenaPerteneceCalculadora(char *);
int esPalabraDecimal(char*);
int automataConstantesEnteras(char*);
int esDecimal(int);
int esHexa(int);
int esOctal(int);
#endif