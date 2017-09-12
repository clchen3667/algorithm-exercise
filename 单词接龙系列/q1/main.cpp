#include <iostream>
#include <vector>
#include <string>

using namespace std;

void swap(vector<string>& vs, int l, int r) {
	string tmp = vs[l];
	vs[l] = vs[r];
	vs[r] = tmp;
}
int res = 0;
void canDragon(vector<string>& vs, int cur) {
	if (res)
		return;
	if (cur == vs.size()) {
		cout << "find solution: " << endl;
		for (auto s : vs)
			cout << s << " ";
		res = 1;
		cout << endl;
	}
	for (int i = cur;i < vs.size();i++) {
		if (cur == 0) {
			swap(vs, cur, i);
			canDragon(vs, cur + 1);
			swap(vs, cur, i);
		} else if (*(vs[cur - 1].end() - 1) == vs[i][0]) {
			swap(vs, cur, i);
			canDragon(vs, cur + 1);
			swap(vs, cur, i);
		}
	}
}

int main() {
	vector<string> vs{"gj", "jl", "dg", "ad", "gg"};
	canDragon(vs, 0);
	if(res)
		cout << 1 << endl;
	else
		cout << -1 << endl;
	return 0;
}
