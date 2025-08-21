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
/**

*/
void solve() {
    int n;
    cin >> n;
    ll x;
    cin >> x;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<ll> dp(n + 2);
    vector<ll> prefix_sum(n + 1);
    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        ll target = x + prefix_sum[i];
        auto it = upper_bound(prefix_sum.begin() + i, prefix_sum.end(), target) - prefix_sum.begin() - 1;
        dp[i] = it - i + dp[it + 1];
    }
    debug(dp);
    ll ans = accumulate(all(dp), 0LL);
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
