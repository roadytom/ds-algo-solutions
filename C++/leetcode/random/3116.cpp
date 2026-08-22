/**
* 3116
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
    long long findKthSmallest(vector<int> &coins, int k) {
        // prune:
        sort(coins.begin(), coins.end());
        vector<int> c;
        for (int x: coins) {
            bool redundant = false;
            for (int exist: c) {
                if (x % exist == 0) {
                    redundant = true;
                    break;
                }
            }
            if (!redundant) c.push_back(x);
        }
        long long max_num = (long long) k * c[0];
        int n = len(c);
        // pre compute LCM of each subset
        vector<long long> LCM;
        vector<int> S;
        for (int mask = 1; mask < (1 << n); mask++) {
            long long curr_lcm = 1;
            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1) {
                    curr_lcm = lcm(curr_lcm, (long long) c[i]);
                    if (curr_lcm > max_num) break;
                }
            }
            if (curr_lcm > max_num) continue;
            LCM.push_back(curr_lcm);
            S.push_back(__builtin_popcount(mask) & 1 ? 1 : -1);
        }
        debug(LCM);
        debug(S);
        auto count = [&](long long x) {
            long long cnt = 0;
            for (int i = 0; i < len(LCM); i++) {
                cnt += S[i] * (x / LCM[i]);
            }
            return cnt;
        };
        long long low = 1, high = max_num;
        while (low <= high) {
            long long mid = (high - low) / 2 + low;
            if (count(mid) >= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution sol;
    vector<int> temp{6, 5};
    debug(sol.findKthSmallest(temp, 1435065516));

    return 0;
}
