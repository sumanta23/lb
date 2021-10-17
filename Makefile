CC=g++
CXXFLAGS=-g -Wall -Wextra -pedantic-errors -MMD -std=c++2a
BUILDINFO=-fdiagnostics-color=always
LDLIBS=-lm -lstdc++
CFLAGS=-I.

# find cpp files in subdirectories
SOURCES := $(shell find src -name '*.cpp')
# find headers
HEADERS := $(shell find src -name '*.h')

BUILD_DIR=build
BIN_DIR=$(BUILD_DIR)/bin
OUTPUT=$(BIN_DIR)/app

all: build

tag:
	ctag c++

clean:
	rm -rf $(BUILD_DIR)

dir:
	mkdir -p $(BIN_DIR)

build: clean dir
	$(CC) $(CXXFLAGS) $(BUILDINFO) $(LDLIBS) $(CFLAGS) -o $(OUTPUT)  $(SOURCES)

