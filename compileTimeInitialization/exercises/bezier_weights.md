# Exercise 3: Efficient Bézier Curve Evaluation for Static Graphics Rendering

## Background

Bézier curves are widely used in vector graphics, animation, and design tools to represent smooth curves. Each point on the curve is evaluated using Bernstein basis polynomials, which in turn rely on binomial coefficients and floating-point exponentiation.

In static rendering systems (e.g., compile-time SVG generation or embedded GUI rendering), evaluating these basis weights at runtime is wasteful and unnecessary.

## Problem Statement

You are developing a rendering system that uses Bézier curves of fixed degree (e.g., 3 or 4) to draw UI elements on an embedded screen. Performance and binary size are critical.

You are required to precompute the basis weights `B_i^n(t)` for a fixed value of `t` in `[0, 1]`. These weights will be used repeatedly to generate curve points without recomputation.

## Task

Implement a program that:
- Computes the binomial coefficients `C(n, i)` using a recursive or static approach
- Evaluates each `B_i^n(t)` basis function for a given `t`
- Ensures that all values are computed statically and are directly usable at runtime

> Hints:
> - Consider leveraging template recursion or compile-time mathematical evaluation
> - Avoid loops or dynamic memory that depend on runtime values
> - The array of weights must be available as a static constant

