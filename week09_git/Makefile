TARGET = myapp
BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
LIB_DIR = lib
INC_DIR = include

CC = gcc
CFLAGS = -c -fPIC -I$(INC_DIR)
LDFLAGS = -L$(LIB_DIR) -lmyops
LINK_FLAGS = -Wl,-rpath=$(shell pwd)/$(LIB_DIR)

OP_OBJS = $(OBJ_DIR)/myadd.o $(OBJ_DIR)/mysub.o $(OBJ_DIR)/mymul.o \
          $(OBJ_DIR)/mydiv.o $(OBJ_DIR)/mypow.o $(OBJ_DIR)/mymod.o

MAIN_OBJ = $(OBJ_DIR)/myapp.o

LIB_NAME = libmyops.so
VERSION = 1.0
SONAME = $(LIB_NAME).1
LIB_TARGET = $(LIB_DIR)/$(LIB_NAME).$(VERSION)

all: $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(TARGET): $(MAIN_OBJ) $(LIB_TARGET)
	@mkdir -p $(BIN_DIR)
	$(CC) $(MAIN_OBJ) -o $@ $(LDFLAGS) $(LINK_FLAGS)
	@echo "Final executable $(BIN_DIR)/$(TARGET) created."

$(LIB_TARGET): $(OP_OBJS)
	@mkdir -p $(LIB_DIR)
	@echo "Creating shared library..."
	$(CC) -shared -Wl,-soname,$(SONAME) -o $@ $(OP_OBJS) -lm
	ln -sf $(LIB_NAME).$(VERSION) $(LIB_DIR)/$(SONAME)
	ln -sf $(SONAME) $(LIB_DIR)/$(LIB_NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -o $@

clean:
	@echo "Cleaning up generated files..."
	rm -rf $(BIN_DIR) $(OBJ_DIR) $(LIB_DIR)