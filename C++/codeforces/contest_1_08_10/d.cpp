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
    vector<int> degree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    if (n == 2) {
        cout << 0 << endl;
        return;
    }
    set<int> leaves;
    function<void(int, int)> dfs = [&](int node, int parent) {
        bool leaf = true;
        if (parent == -1 && tree[node].size() == 1) {
            leaf = false;
            leaves.insert(node);
        }
        for (int child: tree[node]) {
            if (child == parent) continue;
            leaf = false;
            dfs(child, node);
        }
        if (leaf) {
            leaves.insert(node);
        }
    };
    dfs(1, -1);
    debug(leaves);
    int min_ans = (int) leaves.size();
    int max_child = 0;
    for (int node = 1; node <= n; node++) {
        int children = 0;
        for (int child: tree[node]) {
            if (leaves.count(child)) {
                children++;
            }
        }
        max_child = max(max_child, children);
    }

    cout << min_ans - max_child << endl;
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
