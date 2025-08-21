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
        cout << "Yes" << endl;
        cout << 1 << endl;
        cout << 1 << " " << 2 << endl;
        return;
    }
    vector<int> leaves;
    function<void(int, int)> dfs = [&](int node, int parent) {
        bool leaf = true;
        if (parent == -1 && tree[node].size() == 1) {
            leaf = false;
            leaves.push_back(node);
        }
        for (int child: tree[node]) {
            if (child == parent) continue;
            leaf = false;
            dfs(child, node);
        }
        if (leaf) {
            leaves.push_back(node);
        }
    };
    dfs(1, -1);
    debug(leaves);
    auto it = max_element(all(degree));
    if (*it == leaves.size()) {
        cout << "Yes" << endl;
        cout << leaves.size() << endl;
        int idx = (int) (it - degree.begin());
        for (auto leaf: leaves) {
            cout << leaf << " " << idx << endl;
        }
    } else {
        cout << "No" << endl;
    }
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
