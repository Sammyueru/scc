# SCC - Copyright (c) 2025 Samm, See LICENSE.txt for license details
# this makefile is used to compile SCC Maker

# toolchains: gcc, llvm, scc
TOOLCHAIN ?= llvm
TARGET    ?= desktop linux x86-32

CC = gcc

# $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
ROOT := ./
SRC := $(ROOT)src/bin/maker
OBJ := $(ROOT)build/objs/bin/maker
BIN := $(ROOT)build/scc/bin

CFLAGS  = -O2
LDFLAGS = 

EXT := 

ifeq ($(TOOLCHAIN),gcc)
CC = gcc
else ifeq ($(TOOLCHAIN),llvm)
CC = clang
else ifeq ($(TOOLCHAIN),scc)
CC = scc-cc
endif

OUT := $(BIN)/maker$(EXT)

CSRC = $(shell find $(SRC) -name '*.c') # $(wildcard $(SRC)/*.c $(SRC)/**/*.c)
COBJ = $(patsubst $(SRC)/%, $(OBJ)/%.o, $(CSRC))

all: $(OUT)

$(ROOT)docs.pdf:
	@mkdir -p $(ROOT)build/docs
	doxygen $(ROOT)docs/doxyfile

docs: $(ROOT)docs.pdf

clean:
	rm -rf $(ROOT)build

$(OBJ)/%.c.o: $(SRC)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT): $(COBJ)
	@mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) $^ -o $(OUT)

