/**
 * 918
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
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = len(nums);
        vector<long long> P(2 * n + 1, 0LL);
        for (int i = 0; i < 2 * n; i++) {
            P[i + 1] = P[i] + nums[i % n];
        }
        long long ans = LLONG_MIN;
        // INDEXES with strictly increasing P values
        // the less is better
        deque<int> dq;
        // EMPTY ARRAY WITH PREFIX_SUM=0
        dq.push_back(0);
        for (int j = 1; j <= 2 * n; j++) {
            while (j - dq.front() > n) {
                dq.pop_front();
            }
            ans = max(ans, P[j] - P[dq.front()]);
            while (!dq.empty() && P[dq.back()] >= P[j]) dq.pop_back();
            dq.push_back(j);
        }
        return (int) ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution sol;
    vector<int> temp{1,-2,3,-2};
    debug(sol.maxSubarraySumCircular(temp));

    return 0;
}