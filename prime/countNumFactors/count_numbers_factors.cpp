#include "all_prime_factors.h"
#include "count_numbers_factors.h"

int count_numbers_factors(long long n) {
	std::vector<long long> prime = all_prime_factors(n);
	int res = 1, count = 1;
	if (prime.empty())
		return count;
	int cur = (int)prime[0];
	for (int i = 1;i < prime.size();i++) {
		if (prime[i] == cur) {
			++count;
		} else {
			res *= (count + 1);
			count = 1;
			cur = (int)prime[i];
		}
	}
	res *= (count + 1);
	return res;
}
