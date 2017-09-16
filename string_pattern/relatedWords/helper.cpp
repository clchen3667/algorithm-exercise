#include "helper.h"
#include <sstream>
#include <cctype>

using namespace std;

void procedure(string& str) {
    for (auto &c : str) {
        if (!isalnum(c))
            c = ' ';
        if (isupper(c)) {
            c = tolower(c);
        }
    }
}

vector<string> split(string str, char delim) {
    stringstream ss;
    string tmp;
    ss << str;
    vector<string> res;
    while (getline(ss,tmp,delim)) {
        if (!tmp.empty() && tmp[0] != ' ')
            res.push_back(tmp);
    }
    return res;
}

