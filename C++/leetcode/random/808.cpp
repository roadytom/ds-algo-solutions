#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
/**

*/
double dp[205][205];

class Solution {
public:
    double soupServings(int n) {
        n = (int) ceil(1.0 * n / 25);
        if (n >= 200) return 1;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < 205; i++) {
            dp[0][i] = 1;
            dp[i][0] = 0;
        }
        dp[0][0] = 0.5;
        vector<pair<int, int> > drs{{4, 0}, {3, 1}, {2, 2}, {1, 3}};
        for (int A = 1; A <= n; A++) {
            for (int B = 1; B <= n; B++) {
                for (auto &[a, b]: drs) {
                    dp[A][B] += dp[max(0, A - a)][max(0, B - b)] / 4;
                }
            }
        }
        return dp[n][n];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    debug(s.soupServings(1));
    return 0;
}
