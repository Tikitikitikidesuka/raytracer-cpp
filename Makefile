# Parameters

TARGET_EXEC := raytracer

BIN_DIR := ./build/bin
OBJ_DIR := ./build/obj
SRC_DIR := ./src
INC_DIR := ./include

CC = gcc
CC_FLAGS = -O3

# Code

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

$(BIN_DIR)/$(TARGET_EXEC): $(OBJS) | $(BIN_DIR)
	$(CC) $(CC_FLAGS) -I $(INC_DIR) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CC_FLAGS) -I $(INC_DIR) -c -o $@ $< 

$(BIN_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@
