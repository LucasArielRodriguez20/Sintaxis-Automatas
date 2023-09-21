BIN = automata.exe
OBJ = columnas.o automata.o
CC = gcc
CFLAGS = -std=c18
RM = rm -f
$(BIN): $(OBJ)	
	$(CC) $(OBJ) -o $(BIN) $(CFLAGS)

automata.o: automata.c columnas.h 
	$(CC) -c automata.c -o automata.o $(CFLAGS)

columnas.o: columnas.h
	$(CC) -c columnas.c -o columnas.o $(CFLAGS)

clean:
	rm -rf *.o automata.exe