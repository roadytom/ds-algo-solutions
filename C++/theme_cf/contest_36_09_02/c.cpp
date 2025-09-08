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
    int n;
    cin >> n;
    v<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int mn = INT_MIN, mx = INT_MAX;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) {
            mn = max(mn, (a[i - 1] + a[i] + 1) / 2);
        }
        if (a[i - 1] < a[i]) {
            mx = min(mx, (a[i - 1] + a[i]) / 2);
        }
    }
    debug(mn, mx);
    if (mn <= mx) {
        if (mn != INT_MIN)
            cout << mn << endl;
        else if (mx != INT_MAX)
            cout << mx << endl;
        else
            cout << 0 << endl;
    } else {
        cout << -1 << endl;
    }
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
