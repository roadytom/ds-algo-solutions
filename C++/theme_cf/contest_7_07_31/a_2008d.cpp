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
    vector<int> p(n);
    rep(i, 0, n) cin >> p[i];
    string color;
    cin >> color;
    vector<int> ans(n, -1);
    vector<int> visited(n, false);
    function<int(int)> dfs = [&](int node) {
        visited[node] = true;
        int next = p[node] - 1;
        int val = color[node] == '0';
        if (!visited[next]) {
            val += dfs(next);
        }
        return val;
    };

    function<void(int, int)> dfs2 = [&](int node, int val) {
        ans[node] = val;
        int next = p[node] - 1;

        if (ans[next] == -1) {
            dfs2(next, val);
        }
    };
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            auto res = dfs(i);
            dfs2(i, res);
        }
    }
    // debug(ans);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
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
