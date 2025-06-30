/* The following program demonstrates compile-time initialization, template
 * metaprogramming and Bentley's principles in action */
#include <array>
#include <iostream>
using namespace std;

constexpr int N = 64;

// A templated struct that generates Pascal's Triangle (binomial coefficients)
// up to N using compile-time initialization
template <int N> 
struct BinomialTable {
  // A 2D array to store binomial coefficients C(n,k)
  array<array<unsigned long long, N + 1>, N + 1> data{};

  // constexpr constructor: Runs at compile time!
  constexpr BinomialTable() {
    for (int n = 0; n <= N; n++) {
      data[n][0] = 1; // C(n,0)=1
      data[n][n] = 1; // C(n,n)=1
    
    	// Filling the rest using Pascal's identity
    	for (int k = 1; k < n; k++) {
      		data[n][k] = data[n - 1][k - 1] + data[n - 1][k];
    	}
	}
  }

  // Function call operator for easy access to C(n,k)
  constexpr unsigned long long operator()(int n, int k) const {
    return data[n][k];
  }
};

// Create a global constexpr object of BinomialTable<N>
// All values are computed and stored at compile time
constexpr auto binom = BinomialTable<N>{};

int main() {
  // Demonstrate usage with some test cases
  cout << "C(5,2 ) = " << binom(5, 2) << "\n";
  cout << "C(10, 3) = " << binom(10, 3) << "\n";
  cout << "C(64, 32) = " << binom(64, 32) << "\n";
  return 0;
}
