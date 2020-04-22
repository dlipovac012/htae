CC = gcc
CFLAGS = w -fno-stack-protector

# directories
BUILD_DIR = BUILD_DIR

$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<


SRC := ./
OBJ := build

SOURCES := $(wildcard *.c)
OBJECTS := $(patsubst %.c, $(OBJ)/%.o, $(SOURCES))

all: $(OBJECTS)
	$(CC) $^ -o $@

$(OBJ)/%.o: %.c
	$(CC) -$(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -rf $(BUILD_DIR)/*
