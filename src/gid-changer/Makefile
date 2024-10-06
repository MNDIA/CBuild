# Define the target architecture and Android API level
ARCH = aarch64
API_LEVEL = 31

# Determine the OS and machine type
OS_NAME = $(shell uname | tr A-Z a-z)
MACHINE = $(shell uname -m)

# Set up the NDK path
NDK_BIN_DIR := toolchains/llvm/prebuilt/$(OS_NAME)-$(MACHINE)/bin
ifdef ANDROID_NDK_LATEST_HOME
    NDK_PATH ?= $(ANDROID_NDK_LATEST_HOME)/$(NDK_BIN_DIR)
else ifdef ANDROID_NDK
    NDK_PATH ?= $(ANDROID_NDK)/$(NDK_BIN_DIR)
endif

# Set up the compiler and linker
CC := $(NDK_PATH)/$(ARCH)-linux-android$(API_LEVEL)-clang
LD := $(NDK_PATH)/ld.lld
STRIP := $(NDK_PATH)/llvm-strip

# Compiler flags
CFLAGS = -Wall -O2 -std=c11

# Source and output directories
SRC_DIR = src/gid-changer
OUT_DIR = target

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)

# Default target
all: $(OUT_DIR) $(OUT_DIR)/gidchanger_release.f $(OUT_DIR)/gidchanger_debug.f

# Release build
$(OUT_DIR)/gidchanger_release.f: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	$(STRIP) $@

# Debug build
$(OUT_DIR)/gidchanger_debug.f: $(OBJS)
	$(CC) $(CFLAGS) -g -o $@ $^

# Compile source files
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Create output directory
$(OUT_DIR):
	mkdir -p $(OUT_DIR)

# Clean up
.PHONY: clean
clean:
	rm -f $(SRC_DIR)/*.o
	rm -rf $(OUT_DIR)
