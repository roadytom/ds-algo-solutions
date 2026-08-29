/**
 * 1748
 * https://codeforces.com/
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
vector<int> tree;

void add_self(int &a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

int add(int a, int b) {
    a += b;
    if (a >= MOD) return a - MOD;
    return a;
}

int query(int nd, int l, int r, int ql, int qr) {
    if (qr < l || ql > r) return 0;
    if (ql <= l && r <= qr) return tree[nd];
    int m = (r - l) / 2 + l;

    return add(query(2 * nd, l, m, ql, qr), query(2 * nd + 1, m + 1, r, ql, qr));
}

void update(int nd, int l, int r, int pos, int val) {
    if (l == r) {
        add_self(tree[nd], val);
        debug(l, r, tree[nd], pos, val);

        return;
    }
    int m = (r - l) / 2 + l;
    if (pos <= m) update(2 * nd, l, m, pos, val);
    else update(2 * nd + 1, m + 1, r, pos, val);
    tree[nd] = 0;
    add_self(tree[nd], tree[2 * nd]);
    add_self(tree[nd], tree[2 * nd + 1]);
}


void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x: arr) {
        cin >> x;
    }
    vector<int> dists(arr.begin(), arr.end());
    sort(dists.begin(), dists.end());
    dists.resize(unique(dists.begin(), dists.end()) - dists.begin());
    for (int i = 0; i < len(arr); i++) {
        arr[i] = lower_bound(dists.begin(), dists.end(), arr[i]) - dists.begin();
    }
    int node_sz = len(dists);
    tree.resize(4 * node_sz, 0);
    int ans = 0;
    for (int x: arr) {
        debug(tree);
        int sm = query(1, 0, node_sz - 1, 0, x - 1);
        add_self(sm, 1);
        add_self(ans, sm);
        debug(x, sm, ans);
        update(1, 0, node_sz - 1, x, sm);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
