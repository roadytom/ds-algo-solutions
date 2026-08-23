/**
 * 2407
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
    int N;
    vector<int> tr;

    static void max_self(int &a, int b) {
        a = max(a, b);
    }

    void update(int nd, int l, int r, int pos, int val) {
        if (l == r) {
            max_self(tr[nd], val);
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m) update(2 * nd, l, m, pos, val);
        else update(2 * nd + 1, m + 1, r, pos, val);
        max_self(tr[nd], tr[2 * nd]);
        max_self(tr[nd], tr[2 * nd + 1]);
    }

    int query(int nd, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return tr[nd];
        int m = (l + r) / 2;
        return max(query(2 * nd, l, m, ql, qr),
                   query(2 * nd + 1, m + 1, r, ql, qr));
    }

public:
    int lengthOfLIS(vector<int> &nums, int k) {
        N = *max_element(nums.begin(), nums.end());
        tr.assign(4 * N + 4, 0);
        int ans = 0;
        for (int num: nums) {
            int low = max(1, num - k), high = num - 1;
            int best = (low <= high) ? query(1, 1, N, low, high) : 0;
            update(1, 1, N, num, best + 1);
            max_self(ans, best + 1);
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution sol;
    vector<int> temp{4,2,1,4,3,4,5,8,15};
    debug(sol.lengthOfLIS(temp, 3));

    return 0;
}
