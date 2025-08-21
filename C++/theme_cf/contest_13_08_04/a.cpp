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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    ll option;
    cin >> option;
    ll prev = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        ll option1 = a[i];
        ll option2 = option - a[i];
        if (option1 > option2) {
            swap(option1, option2);
        }
        if (prev > option2) {
            cout << "NO" << endl;
            return;
        }

        if (option1 >= prev) {
            prev = option1;
        } else {
            prev = option2;
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
