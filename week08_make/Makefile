
CC = gcc
AR = ar

PROJ_DIR = $(PWD)
SRC_DIR = $(PROJ_DIR)/src
OBJ_DIR = $(PROJ_DIR)/obj
LIB_DIR = $(PROJ_DIR)/lib
BIN_DIR = $(PROJ_DIR)/bin
INC_DIR = $(PROJ_DIR)/include

BASIC_OBJS = $(OBJ_DIR)/add.o $(OBJ_DIR)/sub.o $(OBJ_DIR)/mul.o $(OBJ_DIR)/div.o
STATIC_LIB = $(LIB_DIR)/libmybasic.a
TARGET = $(BIN_DIR)/myapp

CFLAGS = -I$(INC_DIR)

LDFLAGS = -L$(LIB_DIR) -lmybasic

.PHONY: all basic clean

all: $(TARGET)

basic: $(STATIC_LIB)

$(TARGET): $(OBJ_DIR)/myapp.o $(STATIC_LIB)
	@mkdir -p $(BIN_DIR) 
	$(CC) $(OBJ_DIR)/myapp.o -o $(TARGET) $(LDFLAGS) 

$(STATIC_LIB): $(BASIC_OBJS)
	@mkdir -p $(LIB_DIR)
	$(AR) rv $@ $^ 

$(OBJ_DIR)/myapp.o: $(SRC_DIR)/myapp.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR) 
	$(CC) -c $< -o $@ $(CFLAGS) 

clean:
	@echo "Cleaning up..."
	rm -rf $(OBJ_DIR)/*.o $(LIB_DIR)/* $(BIN_DIR)/* 