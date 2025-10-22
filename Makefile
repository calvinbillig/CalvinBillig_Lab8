
# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Default target: compile both programs
all: Lab8_Problem1 Lab8_Problem2

# Compiles Lab8_Problem1.c (NFL Score)
Lab8_Problem1: Lab8_Problem1.c
	$(CC) $(CFLAGS) -o Lab8_Problem1 Lab8_Problem1.c

# Compiles Lab8_Problem2.c (Temperature Conversion)
Lab8_Problem2: Lab8_Problem2.c
	$(CC) $(CFLAGS) -o Lab8_Problem2 Lab8_Problem2.c

# Cleans up generated executables
clean:
	rm -f Lab8_Problem1 Lab8_Problem2 *.o

