/* The following program demonstrates Template-Based Compile-Time Bernstein Basis) */
#include <array>
#include <iostream>
using namespace std;

// Compute binomial coefficient at compile-time via template recursion
template <int N, int K>
struct Binomial {
	static constexpr unsigned long long value =
		Binomial<N-1, K-1>::value + Binomial<N-1, K>::value;
};

template <int N>
struct Binomial<N, 0> {
	static constexpr unsigned long long value = 1;
};

template <int N>
struct Binomial<N, N> {
	static constexpr unsigned long long value = 1;
};

// Power function at compile time
constexpr float pow_const(float base, int exp) {
	float result = 1.0f;
	for (int i=0; i<exp ; i++) {
		result *= base;
	}
	return result;
}

// Evauate Bernstein basis Bi^n(t)
template <int N,int I>
constexpr float bernstein(float t) {
	return Binomial<N, I>::value * pow_const(t, I) * pow_const(1.0f - t, N-I);
}

// Evaluate all Bi^n(t) for fixed N, t
template <int N>
constexpr array<float, N+1> compute_bernstein_basis(float t) {
	array<float, N+1> basis{};

	for(int i=0; i<=N; i++) {
		//Dispatch compile-time bernstein computation
		switch (i) {
			case 0: basis[0] = bernstein<N, 0>(t); break;
			case 1: basis[1] = bernstein<N, 1>(t); break;
			case 2: basis[2] = bernstein<N, 2>(t); break;
			case 3: basis[3] = bernstein<N, 3>(t); break;
			case 4: basis[4] = bernstein<N, 4>(t); break;
		}
	}
	return basis;
}

//Use degree 4 Bezier
constexpr int DEGREE = 4;
constexpr float T = 0.3f;
constexpr auto weights = compute_bernstein_basis<DEGREE>(T);

int main() {
	cout << "Compile-Time Bernstein Basis Weights (n = " << DEGREE << ", t = " << T << "):\n";

	for(float w : weights) {
		cout << w << " ";
	}
	cout << "\n";
}
