#include "kmp.h"
using namespace std;

vector<int> build_failure_function(const string& pattern) {
	vector<int> F(pattern.length(), 0);
	for (int i = 2;i <= pattern.length();i++) {
		// j is the index of the largest next partial match of the string under index i-1
		int j = F[i - 1];
		for ( ; ; ) {
			// check to see if the last character of string i (pattern[i - 1]) "expands" the current "candidate" best partial match(the prefix under index j)
			if (pattern[i - 1] == pattern[j]) {
				F[i] = j + 1;
				break;
			}
			// if we cannot "expand" even the empty string
			if (j == 0) {
				F[i] = 0;
				break;
			}
			// else go to the next best "candidate" partial match
			j = F[j];
		}
	}
	return F;
}

int KMP(const string& text, const string& pattern) {
	vector<int> F = build_failure_function(pattern);
	int res = 0;
	// i:the initial state of the automaton is the empty string
	// j:the first character of the text
	int i = 0, j = 0;
	for ( ; ; ) {
		// if we reached the end of the text;
		if (j == text.length()) break;
		// if the current character of the text "expands" the current match
		if (text[j] == pattern[i]) {
			i++;
			j++;
			if (i == pattern.length()) {
				++res;
				i = F[i];
			}
		}
		// if the current state is not zero, we try to "expand" the next best match
		else if (i > 0)
			i = F[i];
		// if we reached the empty string and failed to "expand", we go to the next character from the text, the state of the automaton remains zero
		else
			++j;
	}
	return res;
}
