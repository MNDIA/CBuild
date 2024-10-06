# Makefile for building gidchanger.c using LLVM for ARM64 Android

# Compiler and tools
NDK_VERSION := 31
NDK_BIN_DIR := toolchains/llvm/prebuilt/linux-x86_64/bin
NDK_PATH ?= $(ANDROID_NDK)/$(NDK_BIN_DIR)
CC := $(NDK_PATH)/aarch64-linux-android$(NDK_VERSION)-clang
STRIP := $(NDK_PATH)/llvm-strip

# Flags
CFLAGS := -Wall -O3 -std=c11
LDFLAGS :=

# Source and target
SRC := gidchanger.c
TARGET_DIR := target
RELEASE_TARGET := $(TARGET_DIR)/release.f
DEBUG_TARGET := $(TARGET_DIR)/debug.f

# Include directories
INCLUDE_DIRS := .
INCLUDE_FLAGS := $(foreach dir,$(INCLUDE_DIRS),-I$(dir))

# Default target
all: $(RELEASE_TARGET) $(DEBUG_TARGET)

# Release build
$(RELEASE_TARGET): $(SRC)
	mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -o $@ $<
	$(STRIP) --strip-unneeded $@
	@echo "Release build directory: $(TARGET_DIR)"


# Debug build
$(DEBUG_TARGET): $(SRC)
	mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) -g $(INCLUDE_FLAGS) -o $@ $<
	@echo "Debug build directory: $(TARGET_DIR)"

# Clean up
.PHONY: clean
clean:
	rm -rf $(TARGET_DIR)
