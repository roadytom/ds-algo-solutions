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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    sort(all(a));
    sort(all(b));
    int ans = 0;
    int a_idx = 0, b_idx = n - 1;
    int taken = 0;
    for (int i = 0; i < k && a_idx < n && b_idx >= 0; i++) {
        if (a[a_idx] >= b[b_idx]) {
            break;
        }
        ans += b[b_idx];
        b_idx--;
        a_idx++;
        taken++;
    }
    a_idx = n - 1;
    while (taken < n) {
        ans += a[a_idx];
        a_idx--;
        taken++;
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
