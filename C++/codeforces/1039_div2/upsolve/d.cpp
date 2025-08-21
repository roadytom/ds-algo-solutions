#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif

using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)

constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;

/**

*/
void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    ll dpiplus1 = 1, dpiplus2 = 0;
    ll res = 1;
    for (int i = n - 2; i >= 0; i--) {
        ll dpi = 0;
        if (p[i] > p[i + 1]) {
            dpi = dpiplus1 + n - i;
        } else {
            dpi = dpiplus2 + n - i;
        }
        res += dpi;
        dpiplus2 = dpiplus1;
        dpiplus1 = dpi;
    }
    vector<vector<ll> > temp;
    temp.push_back({1, 2, 3, 45});
    temp.push_back({8, 2, 3, 2});
    temp.push_back({3, 2, 3, 0});
    temp.push_back({1, 9, 4, 5});
    debug(temp);
    cout << res << endl;
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
