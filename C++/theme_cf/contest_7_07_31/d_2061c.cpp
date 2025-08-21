#include <bits/stdc++.h>
#include <atcoder/modint.hpp>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;
using namespace atcoder;

#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
/**

*/
constexpr ll MOD = 998244353;
using mint = static_modint<MOD>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    // TOTAL = nth person honest + nth person liar(n-1 must be honest) -> nth person honest + (n - 1)th person hones
    //  The number of valid configurations for the first i classmates, where the i-th person is Honest.
    vector<mint> dp(n + 1);
    dp[0] = 1;
    dp[1] = a[0] == 0;
    if (n >= 2) {
        dp[2] = (a[1] == a[0] ? dp[1] : 0) + (a[1] == 1);
    }
    for (int i = 2; i < n; i++) {
        dp[i + 1] = (a[i] == a[i - 1] ? dp[i] : 0) + (a[i - 2] == a[i] - 1 ? dp[i - 1] : 0);
    }
    cout << dp[n] + dp[n - 1] << endl;
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
