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
void dfs(int node, int parent, vector<int> &leaf_count, vector<vector<int> > &tree) {
    bool leaf = true;
    for (int child: tree[node]) {
        if (child == parent) {
            continue;
        }
        leaf = false;
        dfs(child, node, leaf_count, tree);
        leaf_count[node] += leaf_count[child];
    }
    if (leaf) {
        leaf_count[node] = 1;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int> > tree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<int> leaf_count(n + 1);
    dfs(1, -1, leaf_count, tree);
    // debug(leaf_count);
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << 1LL * leaf_count[x] * leaf_count[y] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
