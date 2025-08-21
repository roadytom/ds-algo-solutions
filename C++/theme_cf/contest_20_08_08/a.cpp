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
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    int count = 0;
    rep(i, 0, n) count += (a[i] < b[i]);
    debug(count);
    if (count > 1) {
        cout << "NO" << endl;
        return;
    } else if (count == 0) {
        cout << "YES" << endl;
        return;
    }


    int idx = -1;
    rep(i, 0, n) {
        if (a[i] < b[i]) {
            idx = i;
            break;
        }
    }
    debug(idx);
    int req = b[idx] - a[idx];
    rep(i, 0, n) {
        if (i == idx) continue;
        if (a[i] - b[i] < req) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
