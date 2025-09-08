#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
#define len(x) static_cast<int>((x).size())
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define v vector
#define len(x) static_cast<int>((x).size())

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
/**

*/
void solve() {
    int n;
    cin >> n;
    v<v<pii> > tree(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        tree[a].emplace_back(b, w);
        tree[b].emplace_back(a, w);
    }
    function<ll(int, int)> dfs = [&](int parent, int node) {
        ll max_cost = 0;
        for (auto &[adj, weight]: tree[node]) {
            if (adj == parent) continue;
            max_cost = max(max_cost, weight + dfs(node, adj));
        }
        return max_cost;
    };
    cout << dfs(-1, 0) << endl;
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
