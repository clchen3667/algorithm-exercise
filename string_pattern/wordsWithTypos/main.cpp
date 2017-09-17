#include <math.h>
#include <iostream>
#include <vector>
#include "helper.h"
#include "strDis.h"

using namespace std;

int main() {
	string s1,s2;
	while (getline(cin, s1)) {
		getline(cin, s2);
		vector<string> res =split(s2);
		int result = 0;
		for (auto s : res) {
			if (s == s1) {
				++result;
			} else if (s.length() == s1.length() && equal_typo(s, s1)) {
				++result;
			} else if (abs((int)s.length() - (int)s1.length()) && diff1_typo(s, s1)) {
				++result;
			}
		}
		cout << "there are " << result << " words in sentence similair with word " << s1 <<  endl;
	}
	return 0;
}
