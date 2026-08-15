/**
 * 97
 * https://leetcode.com/problems/
 */
#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

#define len(x) static_cast<int>((x).size())

// Constants
constexpr long long MOD = 1e9 + 7;
constexpr long long INF = 1e18;
constexpr long long MAXN = 2e6 + 5; // for factorial precomputation etc.
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if (n1 + n2 != n3) return false;
        if (n1 == 0) return s2 == s3;
        if (n2 == 0) return s1 == s3;
        vector<vector<bool> > dp(n1 + 1, vector<bool>(n2 + 1, false));
        dp[0][0] = true;

        // for (int i = 1; i <= n1; i++) {
        //     for (int j = 1; j <= n2; j++) {
        //         dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1])
        //         || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
        //     }
        // }

        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                } else {
                    if (i > 0 && s1[i - 1] == s3[i + j - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                    if (j > 0 && s2[j - 1] == s3[i + j - 1]) {
                        dp[i][j] = dp[i][j] || dp[i][j - 1];
                    }
                }
            }
        }

        return dp[n1][n2];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution sol;
    // vector<int> temp{1, 2};
    // debug(sol.method(temp));

    return 0;
}
