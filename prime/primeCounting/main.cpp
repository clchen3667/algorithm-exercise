#include <iostream>
#include "prime_counting.h"
using namespace std;

int main() {
	int num;
	while (cin >> num) {
		cout << "there are " << prime_counting(num) << " prime numbers <= " << num << endl;
	}
	return 0;
}
