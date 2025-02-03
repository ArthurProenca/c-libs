# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra

# Target executable
TARGET = c-libs

SRCS = $(wildcard src/**/*.c) src/main.c
OBJS = $(SRCS:.c=.o)

# Declare phony targets
.PHONY: all clean clean-obj install

# Default build rule
all: $(TARGET) clean-obj  # Run clean-obj after successful build

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Compile each .c file to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove only .o files after successful build
clean-obj:
	rm -f $(OBJS)

# Clean all compiled files
clean:
	rm -f $(OBJS) $(TARGET)

# Install binary (optional)
install: $(TARGET)
	cp $(TARGET) /usr/local/bin/
