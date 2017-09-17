#include <queue>
#include "bfs.h"

using namespace std;

vector<vector<int>> compute_dis(vector<vector<int>>& maze, int x, int y) {
    int m = (int)maze.size();
    int n = (int)maze[0].size();
    vector<vector<int>> res(m, vector<int>(n, -1));
    res[x][y] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        if (cur.first - 1 > 0 && maze[cur.first - 1][cur.second] != 1 && res[cur.first - 1][cur.second] == -1) {
            res[cur.first - 1][cur.second] = res[cur.first][cur.second] + 1;
            q.push(make_pair(cur.first - 1, cur.second));
        }
        if (cur.first + 1 < maze.size() && maze[cur.first + 1][cur.second] != 1 && res[cur.first + 1][cur.second] == -1) {
            res[cur.first + 1][cur.second] = res[cur.first][cur.second] + 1;
            q.push(make_pair(cur.first + 1, cur.second));
        }
        if (cur.second - 1 > 0 && maze[cur.first][cur.second - 1] != 1 && res[cur.first][cur.second - 1] == -1) {
            res[cur.first][cur.second - 1] = res[cur.first][cur.second] + 1;
            q.push(make_pair(cur.first, cur.second - 1));
        }
        if (cur.second + 1 > 0 && maze[cur.first][cur.second + 1] != 1 && res[cur.first][cur.second + 1] == -1) {
            res[cur.first][cur.second + 1] = res[cur.first][cur.second] + 1;
            q.push(make_pair(cur.first, cur.second + 1));
        }
    }
    return res;
}
