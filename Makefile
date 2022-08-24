# Parameters

TARGET_EXEC := raytracer

MAIN_SRC_NAME := main

SRC_DIR := ./src
INC_DIR := ./include
TEST_DIR := ./test

BIN_DIR := ./build/bin
OBJ_DIR := ./build/obj/src
BIN_TEST_DIR := ./build/bin/test
OBJ_TEST_DIR := ./build/obj/test

CC = g++
SHELL = bash

CC_FLAGS = -O3 -std=c++11 -Wall
CC_TEST_FLAGS = -O3 -std=c++11 -Wall

# Code

.PRECIOUS: $(OBJ_DIR)/%.o $(OBJ_TEST_DIR)/%.o

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
SRCS:= $(filter-out $(SRC_DIR)/$(MAIN_SRC_NAME).cpp, $(SRCS))
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
MAIN_OBJ := $(OBJ_DIR)/$(MAIN_SRC_NAME).o

TEST_SRCS := $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS := $(patsubst $(TEST_DIR)/%.cpp, $(OBJ_TEST_DIR)/%.o, $(TEST_SRCS))
TEST_BINS := $(patsubst $(TEST_DIR)/%.cpp, $(BIN_TEST_DIR)/%, $(TEST_SRCS))

$(BIN_DIR)/$(TARGET_EXEC): $(OBJS) $(MAIN_OBJ) | $(BIN_DIR)
	@echo Building \"$(TARGET_EXEC)\" at \"$(BIN_DIR)/$(TARGET_EXEC)\"...
	$(CC) $(CC_FLAGS) -I $(INC_DIR) -o $@ $(OBJS) $(MAIN_OBJ)
	@echo Done.

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo Compiling source \"$<\"...
	$(CC) $(CC_FLAGS) -I $(INC_DIR) -c -o $@ $< 
	@echo Done.

$(BIN_TEST_DIR)/%: $(OBJ_TEST_DIR)/%.o $(OBJS) | $(BIN_TEST_DIR)
	@echo Building test \"$@\"...
	$(CC) $(CC_TEST_FLAGS) -I $(INC_DIR) -o $@ $^

$(OBJ_TEST_DIR)/%.o: $(TEST_DIR)/%.cpp | $(OBJ_TEST_DIR)
	@echo Compiling test \"$<\"...
	$(CC) $(CC_TEST_FLAGS) -I $(INC_DIR) -c -o $@ $<
	@echo Done.

$(BIN_DIR):
	@mkdir -p $@

$(OBJ_DIR):
	@mkdir -p $@

$(BIN_TEST_DIR):
	@mkdir -p $@

$(OBJ_TEST_DIR):
	@mkdir -p $@

.PHONY: check clean

check: $(TEST_BINS)
	@$(SHELL) -c '								\
	for bin in $(TEST_BINS);	\
	do									\
		echo Running test $$bin...;					\
		if ! $$bin;							\
		then								\
			exit 1;							\
		fi;								\
	done									\
	'

clean:
	@rm -rf $(BIN_DIR) $(OBJ_DIR) $(BIN_TEST_DIR) $(OBJ_TEST_DIR)
