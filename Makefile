BIN = calculadora.exe
OBJ = ./automata/columnas.o ./automata/automata.o verificacion.o stack.o calculadora.o 
CC = gcc
CFLAGS = -std=c18
RM = rm -f
$(BIN): $(OBJ)	
	$(CC) $(OBJ) -o $(BIN) $(CFLAGS)

calculadora.o: calculadora.c
	$(CC) -c calculadora.c -o calculadora.o $(CFLAGS)

stack.o: stack.c
	$(CC) -c stack.c -o stack.o $(CFLAGS)

verificacion.o: verificacion.c
	$(CC) -c verificacion.c -o verificacion.o $(CFLAGS)

automata.o: ./automata/automata.c
	$(CC) -c ./automata/automata.c -o ./automata/automata.o $(CFLAGS)

columnas.o: ./automata/columnas.c
	$(CC) -c ./automata/columnas.c -o ./automata/columnas.o $(CFLAGS)

clean:
	rm -rf *.o calculadora.exe