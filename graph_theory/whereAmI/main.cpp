#include <iostream>
#include <vector>
#include <string>
#include "find_start.h"
#include "bfs.h"

using namespace std;

int main() {
    int N,M,P,Q;
    while(cin >> N >> M >> P >> Q) {
        int x,y;
        cin >> x >> y;
        vector<vector<int>> maze(N + 1, vector<int>(M + 1, 1));
        vector<vector<int>> surroudings(P + 1, vector<int>(Q + 1, 1));
        
        string tmp;
        
        for (int i = 1;i <= N;i++) {
            cin >> tmp;
            for (int j = 1;j <= M;j++) {
                maze[i][j] = tmp[j - 1] - '0';
            }
        }
        for (int i = 1;i <= P;i++) {
            cin >> tmp;
            for (int j = 1;j <= Q;j++) {
                surroudings[i][j] = tmp[j - 1] - '0';
            }
        }
        vector<pair<int, int>> starts = find_start(maze, surroudings);
        
        if (starts.size() == 0)
            cout << -1 << endl;
        else {
            vector<vector<int>> dis = compute_dis(maze, x, y);
            int max_dis = 0;
            for (auto p : starts) {
                if (dis[p.first][p.second] == -1) {
                    cout << -2 << endl;
                    break;
                } else
                    max_dis = max(max_dis, dis[p.first][p.second]);
            }
            cout << max_dis << endl;
        }
    }
    return 0;
}
