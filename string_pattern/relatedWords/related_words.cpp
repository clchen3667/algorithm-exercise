#include <map>
#include "related_words.h"
using namespace std;

string relatedWords(const vector<string>& res, const string& pattern, int dis) {
	string result;
	map<string, int> repo;
	int cur = 0, length = (int)res.size(), max_count = 0;
	for (int i = 0;i < res.size(); i++) {
            if (res[i] == pattern) {
                int left = max(0,i - dis);
                int right = min(i + dis, length - 1);
                left = max(cur, left);
                cur = right + 1;
                for (int j = left; j <= right; ++j) {
                    if (res[j] != pattern && repo.find(res[j]) == repo.end()) {
                        repo.insert(make_pair(res[j], 1));
                    }
                    else
                        ++repo[res[j]];
                }
            }
	}
    for (auto p : repo) {
		if (p.second > max_count) {
			max_count = p.second;
            result = p.first;
        }
    }
	if (repo.size() == 0)
		return "N/A";
	else
		return result;
}
