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
    vector<int> parents(n);
    vector<vector<int> > tree(n);
    vector<int> c(n);
    int root = -1;
    rep(i, 0, n) {
        cin >> parents[i] >> c[i];
        if (parents[i] == -1) {
            root = i;
        } else {
            tree[parents[i] - 1].push_back(i);
        }
    }
    vector<int> to_be_deleted;
    function<void(int, int)> dfs = [&](int node, int parent) {
        bool res = c[node] && (node != root);
        for (int child: tree[node]) {
            if (child == parent) continue;
            res = res && c[child];
            dfs(child, node);
        }
        if (res) to_be_deleted.push_back(node);
    };
    dfs(root, -1);
    sort(all(to_be_deleted));
    for (int el: to_be_deleted) {
        cout << el + 1 << " ";
    }
    if (to_be_deleted.empty()) {
        cout << -1;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
