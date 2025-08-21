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
void solve() {
    int n;
    cin >> n;
    vector<ll> d(n);
    rep(i, 0, n) cin >> d[i];
    if (n <= 2) {
        cout << 0 << endl;
        return;
    }
    sort(rall(d));
    debug(d);
    ll prefix_sum = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += i * d[i] - prefix_sum;
        if (i + 1 < n)
            ans += d[i] - d[i + 1];
        prefix_sum += d[i];
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
