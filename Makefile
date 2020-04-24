CC = gcc
CFLAGS = -w -fno-stack-protector

# directories
BUILD_DIR = build

$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<


VSRC := ./
OBJ := build

#SOURCES := $(wildcard *.c)
#OBJECTS := $(patsubst %.c, $(OBJ)/%.o, $(SOURCES))

#all: $(OBJECTS)
#	$(CC) $^ -o $@

#$(OBJ)/%.o: %.c
#	$(CC) -$(CFLAGS) -c $< -o $@

bitwise: $(BUILD_DIR)/bitwise.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ notekeeper.c

notekeeper: $(BUILD_DIR)/notekeeper.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ notekeeper.c

notekeeper: $(BUILD_DIR)/notekeeper.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ notekeeper.c
notekeeper: $(BUILD_DIR)/notekeeper.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ notekeeper.c
notekeeper: $(BUILD_DIR)/notekeeper.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ notekeeper.c
notekeeper: $(BUILD_DIR)/notekeeper.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ notekeeper.c
notekeeper: $(BUILD_DIR)/notekeeper.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ notekeeper.c
.PHONY: clean

clean:
	rm -rf $(BUILD_DIR)/*
