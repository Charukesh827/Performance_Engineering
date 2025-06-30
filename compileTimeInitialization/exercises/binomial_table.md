# Exercise 1: Optimizing Combinatorial Computations in Real-Time Analytics

## Background

In many real-time analytics applications, such as fraud detection, feature engineering, and predictive modeling, it’s often necessary to compute combinations of values — e.g., "choose k out of n" — millions of times per second. Computing binomial coefficients at runtime using factorials or recursive functions quickly becomes a bottleneck.

## Problem Statement

You're tasked with building a performance-critical subroutine for a large-scale analytics engine that repeatedly calculates binomial coefficients as part of probabilistic predictions.

The main constraints are:
- Low-latency access to the coefficient values
- No dynamic memory allocations allowed
- Execution must be deterministic and efficient

## Task

Design and implement a component that stores all binomial coefficients `C(n, k)` up to a given value of `n_max` in an efficient manner. The structure must be fully initialized before runtime, allowing constant-time lookup during execution.

> Hints:
> - You may want to precompute the values using Pascal's Triangle.
> - The method of storage should avoid heap allocations.
> - Explore modern C++ features that support compile-time evaluation.


