# define the C compiler to use
CXX=g++
LINK=${CXX}

# define any compile-time flags
CXXFLAGS=-g -Wall -Wextra -fPIC -pedantic-errors -std=c++2a -fdiagnostics-color=always -pthread

# define any directories containing header files other than /usr/include
#
INCLUDES=-I.  -I`pwd`/src/include -I./third/

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LDFLAGS=-std=c++2a -Wl,-rpath, -pthread

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
LDLIBS=-lm -lstdc++  -lpthread

SRC =$(wildcard src/LeaderBoard/*.cpp src/*.cpp)
OBJ=$(addsuffix .o, $(basename $(SRC)))
TARGET=app

BUILD_DIR=build
BIN_DIR=$(BUILD_DIR)/bin
OUTPUT=$(BIN_DIR)/app


.PHONY: all clean
all: $(TARGET)

$(TARGET): $(OBJ)
	$(LINK) $(LDFLAGS) $(INCLUDES) $^ -o "$@" $(LDLIB)

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $(LDLIBS) $(INCLUDES) -o "$@" "$<"

clean:
	rm -f $(TARGET)
	rm -f ${OBJ}

tag:
	ctag c++
