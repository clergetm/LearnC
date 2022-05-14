CC=gcc
INCDIRS=-I.
OPT=-O3
CFLAGS=-Wall -Wextra -g $(INCDIRS) $(OPT)

CFILES=main.c message.c
OBJECTS=main.o message.o

BINARY=bin

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

# regular expression where % is a wildcard
%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(BINARY) $(OBJECTS) *.exe