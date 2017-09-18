#ifndef TheCowDivTwo_h
#define TheCowDivTwo_h

#include <vector>
using namespace std;

class TheCowDivTwo {
public:
    int find(int N, int K) {
        //dp[p][k][s]:指在序列p,p+1,...,N-1中，选取k个数，使得这k数之和 % N == s
        //TODO : 改为滚动数组节省空间
        //题意是求 dp[0][K][0]
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(K + 1, vector<int>(N + 1, 0)));
        for (int p = N; p >= 0; --p) {
            for (int k = 0; k <= K; ++k) {
                for (int s = 0; s < N; ++s) {
                    if (k == 0) {
                        if (s == 0) {
                            dp[p%2][k][s] = 1;
                        } else {
                            dp[p%2][k][s] = 0;
                        }
                    } else if (p == N) {
                        dp[p%2][k][s] = 0;
                    } else {
                        dp[p%2][k][s] = dp[(p+1)%2][k-1][(s-p+N)%N]
                        + dp[(p+1)%2][k][s];
                        dp[p%2][k][s] %= 1000000007;
                    }
                }
            }
        }
        return (int)dp[0][K][0];
    }
};


#endif /* TheCowDivTwo_h */
