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
#define mp make_pair

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
/**

*/
void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(all(a));
    vector<ll> prefix_sum(n + 1);
    partial_sum(all(a), prefix_sum.begin() + 1);
    while (q--) {
        int b;
        cin >> b;
        auto it = lower_bound(all(a), b) - a.begin();
        if (it == n) {
            cout << -1 << endl;
            continue;
        }
        ll left = prefix_sum[it];
        ll right = 1LL * (n - it) * (b - 1);
        cout << left + right + 1 << endl;
    }
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
