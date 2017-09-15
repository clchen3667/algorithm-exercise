#include <math.h>
#include "all_prime_factors.h"

std::vector<long long> all_prime_factors(long long n) {
	std::vector<long long> result;
	if (n == 1)
		return result;
	for (long long i = 2;i <= sqrt(n);i++) {
		while (n % i == 0) {
			result.push_back(i);
			n /= i;
		}
	}
	if (n != 1) {
		result.push_back(n);
	}
	return result;
}
