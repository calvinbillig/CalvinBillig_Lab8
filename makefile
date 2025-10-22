# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Targets
all: nfl_score temp_convert

# Compiles NFL Score program
nfl_score: nfl_score.c
	$(CC) $(CFLAGS) -o nfl_score nfl_score.c

# Compiles Temperature Conversion program
temp_convert: temp_convert.c
	$(CC) $(CFLAGS) -o temp_convert temp_convert.c

# Cleans up generated files
clean:
	rm -f nfl_score temp_convert *.o

