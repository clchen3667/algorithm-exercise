#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<long long> all_prime_factors(long long n) {
	vector<long long> result;
	for (int i = 2;i <= sqrt(n);i++) {
		while (n % i == 0) {
			result.push_back(i);
			n /= i;
		}
	}
	if (n != 1)
		result.push_back(n);
	return result;
}

int main() {
	long long num;
	while(cin >> num) {
		vector<long long> vec = all_prime_factors(num);
		for (auto n : vec) {
			cout << n << " ";
		}
		cout << endl;
	}
	return 0;
}
