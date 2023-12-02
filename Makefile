CXX = g++
CXX_FLAGS = -g -std=c++17 -pedantic -Wall -Wextra -Werror -Wshadow \
	-Wconversion -Wunreachable-code
BUILD_DIR = ./Build

all: Main

Main: Main.cpp
	$(CXX) $(CXX_FLAGS) -o $(BUILD_DIR)/Main Main.cpp

clean:
	rm -f $(BUILD_DIR)/Main