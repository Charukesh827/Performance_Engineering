# Exercise 2: Embedded Signal Smoothing with Compile-Time Gaussian Filters

## Background

In embedded systems or digital signal processors (DSPs), Gaussian filters are commonly used for smoothing sensor data (e.g., accelerometer noise reduction or image pre-processing). However, floating-point computation of the Gaussian kernel at runtime is costly on such platforms.

## Problem Statement

You are designing a software module for a real-time embedded sensor processing pipeline. The module requires applying a 1D Gaussian blur to a stream of values using a fixed kernel size and standard deviation.

Your goal is to ensure:
- The Gaussian kernel is calculated exactly once
- The kernel values are available before the first data sample is processed
- The implementation is compatible with low-resource environments

## Task

Implement a 1D Gaussian kernel generator that:
- Calculates the filter weights using the Gaussian formula
- Normalizes the weights
- Ensures all computation is resolved at compile time

> Hints:
> - Runtime floating-point computation is discouraged
> - Consider using compile-time constructs that enforce evaluation prior to runtime
> - Avoid using any standard math library functions at runtime

