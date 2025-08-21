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
    vector<pair<ll, int> > a(n);
    rep(i, 0, n) {
        ll x;
        cin >> x;
        a[i] = {x, i};
    }
    vector<pair<ll, int> > b(n);
    rep(i, 0, n) {
        ll x;
        cin >> x;
        b[i] = {x, i};
    }
    vector<pair<ll, int> > c(n);
    rep(i, 0, n) {
        ll x;
        cin >> x;
        c[i] = {x, i};
    }
    sort(all(a), greater());
    sort(all(b), greater());
    sort(all(c), greater());
    // debug(a);
    // debug(b);
    // debug(c);
    ll max_val = 0;
    rep(i, 0, 3) {
        auto &[score_a, day_a] = a[i];
        rep(j, 0, 3) {
            auto &[score_b, day_b] = b[j];
            if (day_a == day_b) continue;
            rep(k, 0, 3) {
                auto &[score_c, day_c] = c[k];
                if (day_c == day_a || day_c == day_b) continue;
                max_val = max(max_val, score_a + score_b + score_c);
            }
        }
    }
    cout << max_val << endl;
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
