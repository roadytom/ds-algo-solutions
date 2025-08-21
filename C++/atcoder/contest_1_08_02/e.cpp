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
    int n, edge, src, dest;
    cin >> n >> edge >> src >> dest;
    src--, dest--;
    vector<vector<int> > graph(n);
    rep(i, 0, edge) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> ans;
    vector<bool> bad(n);
    vector<bool> visited(n);

    function<void(int)> dfs = [&](int node) {
        visited[node] = true;
        for (int adj: graph[node]) {
            if (!visited[adj] && !bad[node]) {
                dfs(adj);
            }
        }
    };

    int itr = src;
    ans.push_back(itr);
    bad[itr] = true;

    while (itr != dest) {
        // debug(itr);
        bad[itr] = true;
        fill(all(visited), false);
        dfs(dest);
        int min_val = INT_MAX;
        for (int adj: graph[itr]) {
            if (visited[adj] && !bad[adj]) {
                min_val = min(min_val, adj);
            }
        }
        itr = min_val;o
        ans.push_back(itr);
    }
    for (int an: ans) {
        cout << an + 1 << " ";
    }
    cout << endl;
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
