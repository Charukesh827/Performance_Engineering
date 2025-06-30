/* The following program shows compile-time initialization via consteval and
 * math approximations */
#include <array>
#include <cmath>
#include <iostream>
using namespace std;

// Constants for compile-time calculation
constexpr int SIZE = 5;       // Must be odd
constexpr float SIGMA = 1.0f; // Standard deviation

// Compile-time exponential function using Taylor expansion
constexpr float exp_approx(float x, int terms = 10) {
  float sum = 1.0f;
  float num = 1.0f;
  float denom = 1.0f;
  for (int i = 1; i <= terms; i++) {
    num *= x;
    denom *= i;
    sum += num / denom;
  }
  return sum;
}

// consteval: must be evaluated at compile time
consteval array<float, SIZE> generate_gaussian_kernel() {
  array<float, SIZE> kernel{};
  constexpr int center = SIZE / 2;
  float sum = 0.0f;

  for (int i = 0; i < SIZE; i++) {
    int x = i - center;
    float exponent = -(x * x) / (2.0f * SIGMA * SIGMA);
    kernel[i] = exp_approx(exponent);
    sum += kernel[i];
  }

  // Normalize the kernel
  for (int i = 0; i < SIZE; i++) {
    kernel[i] /= sum;
  }
  return kernel;
}

// Generate the kernel at compile time
constexpr auto kernel = generate_gaussian_kernel();

int main() {
  cout << "Compile-Time 1D Gaussian Kernel:\n";
  for (float w : kernel) {
    cout << w << " ";
  }
  cout << "\n";
  return 0;
}
