/**
 * 2213
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
    struct Node {
        int pre, suf, best, len;
        char lc, rc;
    };

    vector<Node> tr;
    string s;

    static Node merge(const Node &a, const Node &b) {
        if (!a.len) return b;
        if (!b.len) return a;
        Node merged{};
        merged.len = a.len + b.len;
        merged.lc = a.lc, merged.rc = b.rc;
        merged.pre = a.pre, merged.suf = b.suf;
        merged.best = max(a.best, b.best);
        if (a.rc == b.lc) {
            merged.best = max(merged.best, a.suf + b.pre);
            if (a.pre == a.len) merged.pre = a.len + b.pre;
            if (b.suf == b.len) merged.suf = b.len + a.suf;
        }
        return merged;
    }

    void build(int nd, int l, int r) {
        if (l == r) {
            tr[nd] = {1, 1, 1, 1, s[l], s[r]};
            return;
        }
        int m = (l + r) / 2;
        build(2 * nd, l, m);
        build(2 * nd + 1, m + 1, r);
        tr[nd] = merge(tr[2 * nd], tr[2 * nd + 1]);
    }

    void update(int nd, int l, int r, int p, char c) {
        if (l == r) {
            tr[nd] = {1, 1, 1, 1, c, c};
            return;
        }
        int m = (l + r) / 2;
        if (p <= m) update(2 * nd, l, m, p, c);
        else update(2 * nd + 1, m + 1, r, p, c);
        tr[nd] = merge(tr[2 * nd], tr[2 * nd + 1]);
    }

public:
    vector<int> longestRepeating(string str, string qc, vector<int> &qi) {
        s = str;
        int n = len(s);
        tr.assign(4 * n, {0, 0, 0, 0, 0, 0});
        build(1, 0, n - 1);
        vector<int> ans(len(qi));
        for (int i = 0; i < len(qi); i++) {
            update(1, 0, n - 1, qi[i], qc[i]);
            ans[i] = tr[1].best;
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution sol;
    vector<int> t{1, 3, 3};
    debug(sol.longestRepeating("babacc", "bcb", t));

    return 0;
}
