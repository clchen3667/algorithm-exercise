#include "find_start.h"

using namespace std;

vector<pair<int, int>> find_start(vector<vector<int>>& maze, vector<vector<int>>& square) {
	vector<pair<int,int>> res;
    int I = (int)maze.size() - 1;
    int J = (int)maze[0].size() - 1;
    int K = (int)square.size() - 1;
    int L = (int)square[0].size() - 1;
    for (int i = 1;i <= I - K + 1;i++) {
        for (int j = 1;j <= J - L + 1;j++) {
            // check (i,j) if the top-left of the square or not
            bool isBreak = false;
            int x = 0,y = 0;
            for (int k = 1;k <= K;k++) {
                for (int l = 1;l <= L;l++) {
                    if (maze[i + k - 1][j + l - 1] == square[k][l]) {
                        continue;
                    }
                    else if (maze[i + k - 1][j + l - 1] == 0 && square[k][l] == 2) {
                        x = k - 1;
                        y = l - 1;
                    } else {
                        isBreak = true;
                        break;
                    }
                }
                if (isBreak)
                    break;
            }
            if (!isBreak) {
                res.push_back(make_pair(i + x, j + y));
            }
        }
    }
    return res;
}
