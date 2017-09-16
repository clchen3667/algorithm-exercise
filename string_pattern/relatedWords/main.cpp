#include <iostream>
#include <string>
#include "related_words.h"
#include "helper.h"

using namespace std;

int main() {
	string text;
	string pattern;
	int dis = 0;
	while (getline(cin, text)) {
		getline(cin, pattern);
		cin >> dis;
		procedure(text);
		vector<string> res = split(text);
		cout << relatedWords(res, pattern, dis) << endl;
		cin.ignore();
	}
	return 0;
}
