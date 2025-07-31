# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Include paths
INCLUDES = -Iinclude -Iutility

# Manually listed source files
SRC = \
	src/main.c \
	src/assembler.c \
	utility/utility.c
#LIBSi
LIBS = -lglfw -lGLEW -lGL -lm

# Derive object files from source files (replace .c → .o)
OBJ = $(SRC:.c=.o)

# Output binary
TARGET = ca

# Rule to link all object files
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS)

# Pattern rule to compile any .c into .o in its own folder
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJ) $(TARGET)


