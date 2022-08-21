# Parameters

TARGET_EXEC := raytracer

BIN_DIR := ./build/bin
OBJ_DIR := ./build/obj
SRC_DIR := ./src
INC_DIR := ./include

CC = g++
CC_FLAGS = -O3 -std=c++17

# Code

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

$(BIN_DIR)/$(TARGET_EXEC): $(OBJS) | $(BIN_DIR)
	$(CC) $(CC_FLAGS) -I $(INC_DIR) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CC_FLAGS) -I $(INC_DIR) -c -o $@ $< 

$(BIN_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

.PHONY: clean

clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)
