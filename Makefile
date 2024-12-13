CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: program

program: baza.o Scooters.o
	$(CC) $(CFLAGS) -o program baza.o Scooters.o

main.o: baza.c Scooters.h
	$(CC) $(CFLAGS) -c baza.c

database.o: Scooters.c Scooters.h
	$(CC) $(CFLAGS) -c Scooters.c

clean:
	rm -f *.o program
