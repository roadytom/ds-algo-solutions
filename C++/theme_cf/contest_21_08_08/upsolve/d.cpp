#include <bits/stdc++.h>
#include <atcoder/modint.hpp>
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
using modint = atcoder::modint998244353;

void solve() {
    int n;
    cin >> n;
    vector<vector<int> > tree(n + 1);
    vector<int> parents(n + 1, -1);
    int root = 1;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        parents[i] = p;
        tree[p].push_back(i);
    }
    vector<int> depth(n + 1);
    function<void(int, int)> dfs = [&](int node, int parent) {
        for (int child: tree[node]) {
            if (child == parent) continue;
            depth[child] = depth[node] + 1;
            dfs(child, node);
        }
    };
    dfs(root, -1);
    map<int, vector<int>> depth_to_node;
    for (int i = 1; i <= n; i++) {
        depth_to_node[depth[i]].push_back(i);
    }

    modint ans = 1;
    int max_depth = *max_element(all(depth));
    modint prev_total = 1;
    vector<modint> dp(n + 1);
    for (int d = 1; d <= max_depth; d++) {
        modint curr_total = 0;
        for (int node: depth_to_node[d]) {
            modint node_val = prev_total;
            if (d != 1) {
                node_val -= dp[parents[node]];
            }
            curr_total += node_val;
            dp[node] = node_val;
        }
        ans += curr_total;
        prev_total = curr_total;
    }
    cout << ans << endl;
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
