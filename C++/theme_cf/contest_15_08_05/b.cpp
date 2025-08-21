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
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    bool all_zero = true;
    rep(i, 0, n) {
        if (a[i] == 0) {
            all_zero = false;
            break;
        }
    }
    if (all_zero) {
        cout << 1 << endl;
        cout << 1 << " " << n << endl;
    } else {
        if (a[0] != 0) {
            cout << 2 << endl;
            cout << 2 << " " << n << endl;
            cout << 1 << " " << 2 << endl;
        } else if (a[n - 1] != 0) {
            cout << 2 << endl;
            cout << 1 << " " << n - 1 << endl;
            cout << 1 << " " << 2 << endl;
        } else {
            cout << 3 << endl;
            cout << 1 << " " << n - 2 << endl;
            cout << 2 << " " << 3 << endl;
            cout << 1 << " " << 2 << endl;
        }
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
