BIN = calculadora.exe
OBJ = stack.o calculadora.o
CC = gcc
CFLAGS = -std=c18
RM = rm -f
$(BIN): $(OBJ)	
	$(CC) $(OBJ) -o $(BIN) $(CFLAGS)

calculadora.o: calculadora.c stack.h 
	$(CC) -c calculadora.c -o calculadora.o $(CFLAGS)

stack.o: stack.h
	$(CC) -c stack.c -o stack.o $(CFLAGS)

clean:
	rm -rf *.o calculadora.exe