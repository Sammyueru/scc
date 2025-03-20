# SCC - Copyright (c) 2025 Samm, See LICENSE.txt for license details
# this makefile is used to compile SCC Maker

# toolchains: gcc, llvm, scc
TOOLCHAIN ?= llvm
TARGET    ?= desktop linux x86-32

CC = gcc

ROOT := $(dir $(abspath $(lastword $(MAKEFIL
E_LIST))))
SRC := $(ROOT)/src/bin/maker

CFLAGS  = -O2
LDFLAGS = 

ifeq ($(TOOLCHAIN),gcc)
CC = gcc
else ifeq ($(TOOLCHAIN),llvm)
CC = clang
else ifeq ($(TOOLCHAIN),scc)
CC = scc-cc
endif

CSRC = $(wildcard $(SRC)/*.c $(SRC)/**/*.c)

