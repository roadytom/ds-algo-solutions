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
int dfs(int node, int parent, vector<vector<int> > &tree) {
    bool leaf = true;
    int res = -1;
    for (int child: tree[node]) {
        if (child == parent)
            continue;
        leaf = false;
        res = dfs(child, node, tree);
    }
    if (leaf) {
        return node;
    }
    return res;
}

int dfs2(int node, int parent, vector<vector<int> > &tree, vector<int> &degrees, vector<int> &path) {
    int degree = 0;
    int max_child = -1;
    int max_path = -1;
    for (int child: tree[node]) {
        if (child == parent) {
            continue;
        }
        degree++;
        int res = dfs2(child, node, tree, degrees, path);
        if (max_path < res) {
            max_path = res;
            max_child = child;
        }
    }
    degrees[node] = degree;
    path[node] = max_child;
    return max_path + 1;
}

int dfs3(int node, int parent, vector<vector<int> > &tree) {
    bool leaf = true;
    int res = 0;
    for (int child: tree[node]) {
        if (child == parent) {
            continue;
        }
        leaf = false;
        res += dfs3(child, node, tree);
    }
    if (leaf || (parent == -1 && tree[node].size() == 1)) {
        // assert(res == 0);
        res++;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int> > tree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    debug(dfs3(1, -1, tree));
    cout << (dfs3(1, -1, tree) + 1) / 2 << endl;
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
