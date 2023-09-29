BIN = calculadora.exe
OBJ = columnas.o automata.o verificacion.o stack.o calculadora.o 
CC = gcc
CFLAGS = -std=c18
RM = rm -f
$(BIN): $(OBJ)	
	$(CC) $(OBJ) -o $(BIN) $(CFLAGS)

calculadora.o: calculadora.c stack.h verificacion.h
	$(CC) -c calculadora.c -o calculadora.o $(CFLAGS)

stack.o: stack.h
	$(CC) -c stack.c -o stack.o $(CFLAGS)

verificacion.o: verificacion.h automata.h columnas.h
	$(CC) -c verificacion.c -o verificacion.o $(CFLAGS)

automata.o: automata.h columnas.h
	$(CC) -c automata.c -o automata.o $(CFLAGS)

columnas.o: columnas.h
	$(CC) -c columnas.c -o columnas.o $(CFLAGS)

clean:
	rm -rf *.o calculadora.exe