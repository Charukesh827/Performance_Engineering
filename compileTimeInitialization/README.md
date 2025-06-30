# Compile-Time Initialization in Modern C++

## Overview

This repository demonstrates the use of compile-time initialization techniques in modern C++ (C++20), organized as a structured set of exercises and solutions. The goal is to show how problems that are traditionally solved at runtime can be efficiently handled during compilation, improving performance, determinism, and safety.

Each example focuses on a different application area and employs a different compile-time strategy including:
- `constexpr` initialization of lookup tables
- `consteval` enforced precomputation
- Template metaprogramming for recursive constructs

## Directory Structure
compileTimeInitialization/
├── exercises/ # Problem descriptions for students
│ ├── binomial_table.md
│ ├── gaussian_kernel.md
│ └── bezier_weights.md
│
├── solutions/ # Complete implementations with shared Makefile
│ ├── Makefile
│ ├── binomial_table.cpp
│ ├── gaussian_kernel.cpp
│ └── bezier_weights.cpp
│
└── README.md # Project documentation

## Build Instructions

Navigate to the `solutions/` directory:

```bash
cd solutions/
make            # Builds all programs
make run-binomial
make run-gaussian
make run-bezier
make clean      # Cleans up all binaries

Requirements:

    A C++20-compliant compiler (GCC ≥ 10, Clang ≥ 11, MSVC ≥ 2019)

Techniques Demonstrated
1. constexpr Tables

Used to build complete data tables (e.g., Pascal's Triangle) at compile time using nested loops in constexpr contexts.
2. consteval Functions

Used to enforce that certain computations (e.g., Gaussian kernel generation) must occur entirely during compilation.
3. Template Metaprogramming

Used to compute recursive structures like binomial coefficients and Bernstein weights through type-level computation.
4. Static Memory Allocation

All solutions avoid dynamic memory, instead using std::array to ensure stack-safe, compile-time allocated structures.

