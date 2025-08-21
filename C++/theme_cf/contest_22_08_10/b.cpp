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
void solve() {
    int n;
    cin >> n;
    vector<vector<int> > tree(n + 1);
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        tree[i].push_back(x);
        tree[x].push_back(i);
    }
    bool ans = true;
    function<int(int, int)> dfs = [&](int node, int parent) {
        debug(node, parent);
        bool is_leaf = true;
        int leaf_count = 0;
        for (int child: tree[node]) {
            if (child == parent) continue;
            is_leaf = false;
            leaf_count += dfs(child, node);
        }
        if (is_leaf) return 1;
        ans = ans && (leaf_count >= 3);
        return 0;
    };
    dfs(1, -1);
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
