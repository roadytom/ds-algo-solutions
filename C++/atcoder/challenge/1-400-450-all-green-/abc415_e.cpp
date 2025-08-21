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
    int rows, cols;
    cin >> rows >> cols;
    v<v<ll> > coins(rows, v<ll>(cols));
    rep(i, 0, rows)
        rep(j, 0, cols)
            cin >> coins[i][j];

    v<ll> ps(rows + cols - 1);
    rep(i, 0, rows + cols - 1)
        cin >> ps[i];
    const ll inf = LLONG_MAX;
    v<v<pll> > dp(rows, v<pll>(cols));
    v<v<bool> > visited(rows, v<bool>(cols, false));
    auto inside = [&](int r, int c) {
        return 0 <= r && r < rows && 0 <= c && c < cols;
    };
    if (rows == 1 && cols == 1) {
        cout << 0 << endl;
        return;
    }
    function<pll(int, int)> dfs = [&](int r, int c) {
        if (!inside(r, c)) {
            return mp(0LL, inf);
        }
        ll p = ps[r + c];
        if (r == 0 && c == 0) {
            return dp[r][c] = mp(coins[0][0] - p, coins[0][0] - p);
        }
        if (visited[r][c]) {
            return dp[r][c];
        }
        visited[r][c] = true;
        auto left = dfs(r - 1, c);
        auto right = dfs(r, c - 1);

        ll mx = max(left.f, right.f);
        ll curr = coins[r][c] - p;
        if (mx >= 0) {
            curr += mx;
        }
        ll path_min = min({left.s, right.s, curr});
        return dp[r][c] = mp(curr, path_min);
    };
    cout << abs(dfs(rows - 1, cols - 2).s, dfs(rows - 2, cols - 1)) << endl;
    debug(dp);
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
