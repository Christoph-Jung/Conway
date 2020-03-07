CC=g++
CFLAGS= -c -Wall -std=c++11
 
all: conway
 
#Als nächstes werden hier alle Objekt-Dateien erwähnt die mit kompiliert werden sollen.
conway: Conway.o
	$(CC) Conway.o -o conway.out

#In diesem Abschnitt werden die einzelnen Befehle zum kompilieren der einzelnen CPP-Dateien ausgeführt.
Conway.o: Conway.cpp
	$(CC) $(CFLAGS) Conway.cpp

#Wenn man nun einmal den Befehl "make" oder "make all" ausgeführt hat sieht man, dass zusätzliche Dateien mit der Endung .o erstellt wurden. Möchte man diese wieder löschen führt man den Befehl "make clean" aus.
clean:
	rm -rf *o conway