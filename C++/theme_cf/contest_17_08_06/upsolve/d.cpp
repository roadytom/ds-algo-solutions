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
int id = 0;

void dfs(int node, vector<int> &components, vector<set<int> > &neighbors) {
    components[node] = id;
    for (int child: neighbors[node]) {
        if (components[child] == -1) {
            dfs(child, components, neighbors);
        }
    }
}

void solve() {
    id = 0;
    int n;
    cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    vector<set<int> > neighbors(n + 1);
    for (int i = 1; i <= n; i++) {
        neighbors[i].insert(a[i]);
        neighbors[a[i]].insert(i);
    }
    // debug(neighbors);
    vector<int> components(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (components[i] == -1) {
            dfs(i, components, neighbors);
            id++;
        }
    }
    debug(components, id);
    vector<int> has_one(id, false);
    for (int i = 1; i <= n; i++) {
        if (neighbors[i].size() == 1) {
            has_one[components[i]] = true;
        }
    }
    // min
    int mn_count = 0;
    bool one_taken = false;
    for (int i = 0; i < id; i++) {
        if (!has_one[i]) mn_count++;
        else if (!one_taken) {
            one_taken = true;
            mn_count++;
        }
    }
    cout << mn_count << " " << id << endl;
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
