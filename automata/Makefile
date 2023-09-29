BIN = automata.exe
OBJ = columnas.o automata.o automataMain.o
CC = gcc
CFLAGS = -std=c18
RM = rm -f
$(BIN): $(OBJ)	
	$(CC) $(OBJ) -o $(BIN) $(CFLAGS)

automataMain.o: automataMain.c
	$(CC) -c automataMain.c -o automataMain.o $(CFLAGS)

automata.o: automata.c
	$(CC) -c automata.c -o automata.o $(CFLAGS)

columnas.o: columnas.c
	$(CC) -c columnas.c -o columnas.o $(CFLAGS)

clean:
	rm -rf *.o automata.exe