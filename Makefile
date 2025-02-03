# Compiler settings
CC ?= gcc
CFLAGS ?= -Wall -Wextra -Werror

# Target executable
TARGET = c-libs
SRCS = main.c
OBJS = $(SRCS:.c=.o)

# Declare phony targets
.PHONY: all clean install

# Default build rule
all: $(TARGET) clean-obj  # Run clean-obj after successful build

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

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
