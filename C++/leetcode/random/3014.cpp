/**
 * 3014
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
    /**
    max = 8
    xxx
    xx
    xx
    xx
    xx
    8 * 1 + 8 * 2
    23
    8 + 8 + 7
    2
    8 * (1 + 2)
    8 * (1 + n) * n / 2 + (total - div * 8) * (n + 1)
     */
    int minimumPushes(string word) {
        int n = len(word);
        int full_groups = n / 8;
        int rem = n - full_groups * 8;
        return 8 * (1 + full_groups) * full_groups / 2 + rem * (full_groups + 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution sol;
    debug(sol.minimumPushes("xycdefghij"));
    return 0;
}
