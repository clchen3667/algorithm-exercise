#include <iostream>
#include <vector>
#include <string>
#include "bfs_graph.h"

using namespace std;

int main() {
    int N, M, S;
    while (cin >> N >> M >> S) {
        vector<pair<int, int>> pairs;
        for (int i = 0;i < M;i++) {
            int first, second;
            cin >> first >> second;
            pairs.push_back(make_pair(first, second));
        }
        vector<vector<int>> graph_matrix = buildGraph(pairs, N);
        cout << bfs_reachable(graph_matrix, S) << endl;
    }
    return 0;
}
