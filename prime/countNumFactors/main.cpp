#include <iostream>
#include "count_numbers_factors.cpp"

using namespace std;

int main() {
	long long n;
	while (cin >> n) {
		cout << n << "'s factors number = " << count_numbers_factors(n) << endl;
	}
	return 0;
}
