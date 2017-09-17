#include <sstream>
#include "helper.h"

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
