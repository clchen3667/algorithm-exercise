#include <iostream>
#include <vector>
#include "heap_maker.h"

using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--) {
		int N,M;
		cin >> N >> M;
		vector<int> res(N + M, 0);
		for (int i =0;i < N + M;i++) {
			cin >> res[i];
		}
		buildMaxHeap(res, N + M);
		cout << res[0];
		for (int i = 1;i < N + M;i++)
			cout << " " << res[i];
		cout << endl;
	}
	return 0;
}
