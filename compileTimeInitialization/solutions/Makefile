# Makefile for Compile-Time Binomial Coefficient Table

# Compiler
CXX = g++

# Flags
CXXFLAGS = -std=c++20 -O2 -Wall -Wextra -pedantic

# Source files
SRC = binomial_table.cpp gaussian_kernel.cpp bezier_weights.cpp

# Target executable
TARGETS = $(SRC:.cpp=)

# Default target
all: $(TARGETS)

# Rule for building each executable
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

#Run targets
run-binomial: binomial_table
	./binomial_table

run-gaussian: gaussian_kernel
	./gaussian_kernel

run-bezier: bezier_weights
	./bezier_weights

#Clean generated binaries
clean:
	rm -f $(TARGETS)
