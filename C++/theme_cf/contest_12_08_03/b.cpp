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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<int> b(m);
    rep(i, 0, m) cin >> b[i];
    sort(all(a));
    sort(all(b));
    ll total = accumulate(all(a), 0LL);
    if (k % 2 == 0) {
        total += max(0, b[m - 1] - a[0]);
        total -= max(0, max(b[m - 1], a[n - 1]) - min(a[0], b[0]));
        cout << total << endl;
    } else {
        total += max(0, b[m - 1] - a[0]);
        cout << total << endl;
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
