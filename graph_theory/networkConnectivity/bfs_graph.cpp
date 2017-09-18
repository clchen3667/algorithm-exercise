#include "bfs_graph.h"
#include <queue>

using namespace std;

vector<vector<int>> buildGraph(vector<pair<int, int>>& pairs, int m) {
    vector<vector<int>> res(m + 1, vector<int>(m + 1, 0));
    for (auto p : pairs) {
        res[p.first][p.second] = res[p.second][p.first] = 1;
    }
    return res;
}

int bfs_reachable(vector<vector<int>>& vec, int point) {
    int res = 0;
    vector<bool> record(vec.size(), false);
    queue<int> q;
    q.push(point);
    record[point] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 1;i < vec.size();i++) {
            if (vec[cur][i] == 1 && record[i] == false) {
                ++res;
                record[i] = true;
                q.push(i);
            }
        }
    }
    return res;
}
