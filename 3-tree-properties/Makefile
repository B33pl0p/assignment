# Directories
SRCDIR = src
OBJDIR = obj

# Compiler and linker configurations
CC = gcc
CFLAGS = -std=c11 -g -Wall -I../include
LIBS = -lm
EXECUTABLE = ./mysolution

# Find all .c files in the src directory
SOURCES = $(wildcard $(SRCDIR)/*.c)
# Replace the src directory with the obj directory and change the file extension to .o
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
# Find all .o files in the obj directory
ALL_OBJECTS = $(wildcard $(OBJDIR)/*.o)

# Default target
all: $(EXECUTABLE)

# Rule to make the executable
$(EXECUTABLE): $(OBJECTS)
	@$(CC) $(CFLAGS) $(ALL_OBJECTS) -o $(EXECUTABLE) $(LIBS)

# Rule to compile .c to .o
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

run: clean all
	./mysolution 7

clean: 
	@rm obj/problem.o

refresh:
	@mkdir -p $(OBJDIR)
	cp ../0-solution/obj/btree_arr.o obj/

mem: 
	valgrind ./mysolution

test: all
	python ../scripts/sanitycheck.py 

install:
	pip install python-benedict 

submit:
	@echo "You are in the wrong folder. cd .. and run make submit from the project directory"


# INSTRUCTOR ONLY
solution:
	gcc -std=c11 -g -Wall -I../include ../obj/*.o src/problem.c -o ./mysolution -lm
	python ../scripts/sanitycheck.py 
update: 
	python ../scripts/generate_solutions.py 

