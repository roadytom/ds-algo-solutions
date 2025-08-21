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
#define pb push_back
#define f first
#define s second
#define v vector

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
/**

*/
void solve() {
    int n;
    cin >> n;
    vi p(n + 1);
    rep(i, 1, n + 1) cin >> p[i];
    vb visited(n + 1);
    ll ans = 0;
    function<ll(int)> dfs = [&](int node) {
        visited[node] = true;
        int next = p[node];
        if (!visited[next]) {
            return 1LL + dfs(next);
        }
        return 1LL;
    };
    for (int node = 1; node <= n; node++) {
        if (!visited[node]) {
            ll path_count = dfs(node);
            if (path_count > 2) {
                ans += (path_count - 1) / 2;
            }
        }
    }
    cout << ans << endl;
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
