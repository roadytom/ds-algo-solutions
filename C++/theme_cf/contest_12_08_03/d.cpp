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


int dfs(int node, int parent, const vector<vector<int> > &tree) {
    for (int child: tree[node]) {
        if (child == parent) continue;
        return dfs(child, node, tree);
    }
    return node;
}

int component_count;


int dfs2(int node, int parent, int x, const vector<vector<int> > &tree) {
    int size = 1;
    for (int child: tree[node]) {
        if (child == parent) continue;
        size += dfs2(child, node, x, tree);
    }
    if (size >= x) {
        component_count++;
        return 0;
    }
    return size;
}

bool check(int any_leaf, int x, int required_component_count, const vector<vector<int> > &tree) {
    component_count = 0;
    dfs2(any_leaf, -1, x, tree);
    return component_count >= required_component_count;
}

/**

*/
void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int> > tree(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int any_leaf = dfs(0, -1, tree);
    int left = 1, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(any_leaf, mid, k + 1, tree)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    assert(right >= 1);
    cout << right << endl;
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
