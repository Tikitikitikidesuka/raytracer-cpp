# Parameters

TARGET_EXEC := raytracer

SRC_DIR := ./src
INC_DIR := ./include
TEST_DIR := ./test

BIN_DIR := ./build/bin
OBJ_DIR := ./build/obj/src
BIN_TEST_DIR := ./build/bin/test
OBJ_TEST_DIR := ./build/obj/test

CC = g++

CC_FLAGS = -O3 -std=c++11
CC_TEST_FLAGS = -O3 -std=c++11

# Code

.PRECIOUS: $(OBJ_DIR)/%.o $(OBJ_TEST_DIR)/%.o

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

TEST_SRCS := $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS := $(patsubst $(TEST_DIR)/%.cpp, $(OBJ_TEST_DIR)/%.o, $(TEST_SRCS))
TEST_BINS := $(patsubst $(TEST_DIR)/%.cpp, $(BIN_TEST_DIR)/%, $(TEST_SRCS))

$(BIN_DIR)/$(TARGET_EXEC): $(OBJS) $(TEST_BINS) | $(BIN_DIR)
	@echo Building \"$(TARGET_EXEC)\" at \"$(BIN_DIR)/$(TARGET_EXEC)\"...
	@$(CC) $(CC_FLAGS) -I $(INC_DIR) -o $@ $(OBJS)
	@echo Done.

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo Compiling \"$<\"...
	@$(CC) $(CC_FLAGS) -I $(INC_DIR) -c -o $@ $< 

$(BIN_TEST_DIR)/%: $(OBJ_TEST_DIR)/%.o | $(BIN_TEST_DIR)
	@echo Building test \"$@\"...
	@$(CC) $(CC_TEST_FLAGS) -I $(INC_DIR) -o $@ $^
	@echo Running test \"$@\"...
	@echo Test output:
	@$@
	@echo End of test output.

$(OBJ_TEST_DIR)/%.o: $(TEST_DIR)/%.cpp | $(OBJ_TEST_DIR)
	@echo Compiling \"$<\"
	@$(CC) $(CC_TEST_FLAGS) -I $(INC_DIR) -c -o $@ $<

$(BIN_DIR):
	@mkdir -p $@

$(OBJ_DIR):
	@mkdir -p $@

$(BIN_TEST_DIR):
	@mkdir -p $@

$(OBJ_TEST_DIR):
	@mkdir -p $@

.PHONY: clean

clean:
	@rm -rf $(BIN_DIR) $(OBJ_DIR)
