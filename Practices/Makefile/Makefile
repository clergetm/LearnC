CC=gcc
INCDIRS=-I.
OPT=-O3
CFLAGS=-Wall -Wextra -g $(INCDIRS) $(OPT)

CFILES=main.c message.c
OBJECTS=main.o message.o

BINARY=out

all: $(BINARY)

$(BINARY): $(OBJECTS)
	@echo "generate executable"
	$(CC) -o $@ $^

# regular expression where % is a wildcard
%.o:%.c
	@echo "generate " $^
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	@echo "clean the project"
# rm -rf $(BINARY) $(OBJECTS)		 	# Linux
	del -rf $(BINARY).exe $(OBJECTS) 	# Windows
	@echo "project cleaned"