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
    v<v<ll> > dp(rows, v<ll>(cols, -1));
    auto inside = [&](int r, int c) {
        return 0 <= r && r < rows && 0 <= c && c < cols;
    };

    function<ll(int, int)> dfs = [&](int r, int c) {
        if (!inside(r, c)) {
            return inf;
        }
        if (dp[r][c] != -1) {
            return dp[r][c];
        }
        ll p = ps[r + c];
        ll min_req = p - coins[r][c];
        if (r == rows - 1 && c == cols - 1) {
            return dp[r][c] = max(0LL, p - coins[r][c]);
        }
        ll left = dfs(r, c + 1);
        ll right = dfs(r + 1, c);
        return dp[r][c] = max(0LL, min(left, right) + min_req);
    };
    cout << dfs(0, 0) << endl;
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
