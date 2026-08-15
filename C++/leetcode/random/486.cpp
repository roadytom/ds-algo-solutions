/**
 * 486
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
    bool predictTheWinner(vector<int> &nums) {
        int n = len(nums);
        vector<vector<long long> > memo(n, vector<long long>(n, -1));
        auto dp = [&](this auto &self, int i, int j)-> long long {
            if (i > j) return 0LL;
            if (memo[i][j] != -1) {
                return memo[i][j];
            }
            // first i + 1, j -> i + 2, j; i + 1, j - 1
            long long f = nums[i] + min(self(i + 2, j), self(i + 1, j - 1));
            // i, j - 1 -> i + 1, j - 1 ; i, j - 2
            long long s = nums[j] + min(self(i + 1, j - 1), self(i, j - 2));
            return memo[i][j] = max(f, s);
        };
        dp(0, n - 1);
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        return memo[0][n - 1] >= sum - memo[0][n - 1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution sol;
    vector<int> temp{1,5,233,7};
    debug(sol.predictTheWinner(temp));

    return 0;
}
