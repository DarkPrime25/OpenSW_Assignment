
CC = gcc
AR = ar

SRC_DIR = ./src
OBJ_DIR = ./obj
LIB_DIR = ../lib
INC_DIR = ../include

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

STATIC_LIB = $(LIB_DIR)/libmyadvanced.a 

CFLAGS = -I$(INC_DIR)

.PHONY: all clean

all: $(STATIC_LIB)

$(STATIC_LIB): $(OBJS)
	mkdir -p $(LIB_DIR)
	$(AR) rcs $@ $^ 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf $(OBJ_DIR)/*.o $(STATIC_LIB)