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
int MAXN = 2e5;
ll dp(int l, int r, vector<ll> &a, vector<ll> &memo) {
    if (l == r) {
        return abs(a[l]);
    }
    if (l > r) {
        return 0LL;
    }
    ll idx = 1LL * l * MAXN + r;
    if (memo[idx] != -1) {
        return memo[idx];
    }
    ll max_coin = 0;
    for (int choose = l; choose <= r; choose++) {
        ll curr = abs(a[choose]);
        if (a[choose] < 0) {
            curr += dp(l, choose - 1, a, memo);
        } else {
            curr += dp(choose + 1, r, a, memo);
        }
        max_coin = max(max_coin, curr);
    }
    memo[idx] = max_coin;
    return max_coin;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<ll> prefix_positive(n);
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) {
            prefix_positive[i] += a[i];
        }
        if (i > 0) {
            prefix_positive[i] += prefix_positive[i - 1];
        }
    }
    vector<ll> prefix_negative(n);
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] < 0) {
            prefix_negative[i] += abs(a[i]);
        }
        if (i < n - 1) {
            prefix_negative[i] += prefix_negative[i + 1];
        }
    }
    debug(prefix_positive, prefix_negative);
    ll max_coin = 0;
    for (int i = 0; i < n; i++) {
        max_coin = max(max_coin, prefix_positive[i] + prefix_negative[i]);
    }
    cout << max_coin << endl;
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
