#include <iostream>
#include "theCowDivTwo.cpp"

using namespace std;

int main() {
	int N, K;
	TheCowDivTwo s;
	while(cin >> N >> K) {
		cout << s.find(N, K) << endl;
	}
	return 0;
}
