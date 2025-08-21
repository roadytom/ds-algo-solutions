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
#define mp make_pair
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
#define v vector
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
/**
 *
 */
void solve() {
    int n, k;
    cin >> n >> k;
    int b, s;
    cin >> b >> s;
    vi p(n + 1);
    rep(i, 1, n + 1) cin >> p[i];
    vl score(n + 1);
    rep(i, 1, n + 1) cin >> score[i];
    vb visited(n + 1, false);
    // vl maxs(n + 1);
    // function<ll(int, ll)> dfs1 = [&](int node, ll parent) {
    //     visited[node] = true;
    //     int next = p[node];
    //     ll res = parent;
    //     if (!visited[next]) {
    //         res = dfs1(next, max(parent, score[node]));
    //     }
    //     res = max(res, score[node]);
    //     maxs[node] = res;
    //     return res;
    // };
    // for (int i = 1; i <= n; i++) {
    //     if (!visited[i]) {
    //         dfs1(i, -1);
    //     }
    // }

    function<ll(int, int)> dfs = [&](int node, int turn_count) {
        visited[node] = true;
        if (turn_count == 0) return 0LL;
        int next = p[node];
        ll curr = score[node];
        ll res = 1LL * turn_count * curr;
        if (!visited[next]) {
            res = max(res, dfs(next, turn_count - 1) + curr);
        }
        return res;
    };

    // debug(maxs);
    fill(all(visited), false);
    auto res = dfs(b, k);
    fill(all(visited), false);
    auto res2 = dfs(s, k);
    debug(res, res2);
    if (res > res2) {
        cout << "Bodya" << endl;
    } else if (res < res2) {
        cout << "Sasha" << endl;
    } else {
        cout << "Draw" << endl;
    }
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
