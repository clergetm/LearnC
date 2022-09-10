# Directories
SRC:=src
OBJ:=obj

# Files
CFILES:= $(wildcard $(SRC)/*.c) # Get all c files from the $(SRC) directory
OBJECTS:= $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(CFILES))

# Compiler
CC:=gcc
INCDIRS:=-I$(SRC) 
OPT:=-O3
#  -g 		adds debugging information to the executable file
#  -Wall	turns on most, but not all, compiler warnings
#  -I		find the header files in this directory.
CFLAGS:=-Wall -Wextra -g $(INCDIRS) $(OPT)
BINARY:=out

all:$(BINARY)

# Create Executable
$(BINARY):$(OBJECTS)
	$(CC) -o $@ $^

# Generate .o files from .c files
$(OBJ)/%.o:$(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@


# Clean command
clean:
	@echo "clean the project"
# 	Linux
# 	rm -rf $(BINARY) $(OBJECTS)		 	

# 	Windows
	del -rf $(BINARY).exe .\$(OBJ)\*.o
	del .\$(SRC)\tempCodeRunnerFile.c
	@echo "project cleaned"
