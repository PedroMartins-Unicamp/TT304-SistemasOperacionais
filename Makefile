CC = gcc
CFLAGS = -Wall -Wextra -pthread
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TARGET = $(BIN_DIR)/program

SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/matrix/*.c) $(wildcard $(SRC_DIR)/threading/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

$(BIN_DIR):
	mkdir -p $@

clean:
	$(RM) -r $(OBJ_DIR) $(BIN_DIR)
