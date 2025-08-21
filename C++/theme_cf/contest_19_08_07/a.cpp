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
bool get_bit(ll num, int pos) {
    return (1LL << pos) & num;
}

void solve() {
    ll x, y;
    cin >> x >> y;
    ll ans = 0;
    for (int i = 0; i < 32; i++) {
        if (get_bit(x, i) == get_bit(y, i)) {
            ans++;
        } else {
            break;
        }
    }
    cout << (1LL << ans) << endl;
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
