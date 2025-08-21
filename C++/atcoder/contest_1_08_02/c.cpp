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
    ll n; cin >> n;
    vector<ll> a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    map<ll, ll> counter;
    ll ans = 0LL;
    for (ll i = 1LL; i <= n; i++) {
        ll target = i - a[i];
        ans += counter[target];
        counter[i + a[i]]++;
    }
    cout << ans << endl;
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
