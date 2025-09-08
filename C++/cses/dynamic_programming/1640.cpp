#include <bits/stdc++.h>
#include <atcoder/modint>
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
#define pb push_back
#define ppb pop_back
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
/**

*/
using mint = atcoder::modint1000000007;

void solve() {
    int n, m;
    cin >> n >> m;
    v<int> arr(n);
    rep(i, 0, n) cin >> arr[i];
    v<v<mint> > dp(n, v<mint>(m + 1));
    if (arr[0] == 0) {
        for (int i = 1; i <= m; i++) {
            dp[0][i] = 1;
        }
    } else {
        dp[0][arr[0]] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int next: {j - 1, j, j + 1}) {
                if (1 <= next && next <= m && (arr[i] == 0 || arr[i] == next)) {
                    dp[i][next] += dp[i - 1][j];
                }
            }
        }
    }
    // debug(dp);
    mint res = accumulate(all(dp[n - 1]), mint{0});
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
