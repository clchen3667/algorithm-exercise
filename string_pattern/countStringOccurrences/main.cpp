#include <iostream>
#include "kmp.h"

using namespace std;

int main() {
	string text;
	string pattern;
	while (getline(cin, text)) {
		getline(cin, pattern);
		cout << "the pattern " << pattern << "found in text " << text << " " << KMP(text, pattern) << " times." << endl;
	}
	return 0;
}
