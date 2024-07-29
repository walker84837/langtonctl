# Define the compiler and the flags
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -march=native -mtune=native -O2 -flto=auto
LDFLAGS = -lraylib -lm

# Define the target executable
TARGET = langtonctl

# Define the source files and object files
SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Link object files to create the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

# Compile source files into object files
%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean

# Display a message with the help
help:
	@echo "Usage:"
	@echo "  make          - build the project"
	@echo "  make clean    - remove build artifacts"
	@echo "  make help     - display this help message"
