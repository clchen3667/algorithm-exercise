#include "prime_counting.h"
#include <vector>

int prime_counting(int n) {
	std::vector<bool> is_prime(n + 1, true);
	int ans = 0;
	for (int i = 2;i <= n;i++) {
		if (is_prime[i]) {
			ans += 1;
			for (long long j = (long long)i * i;j <= n;j += i) {
				is_prime[j] = false;
			}
		}
	}
	return ans;
}
