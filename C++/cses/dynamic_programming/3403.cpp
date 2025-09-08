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
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define v vector

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
    int A, B;
    cin >> A >> B;
    v<int> a(A), b(B);
    rep(i, 0, A) cin >> a[i];
    rep(i, 0, B) cin >> b[i];
    v<v<int> > dp(A + 1, v<int>(B + 1));
    v<v<pii> > parent(A + 1, v<pii>(B + 1));
    auto maxi = [&](int r1, int c1, int r2, int c2, int cost) {
        if (dp[r2][c2] < dp[r1][c1] + cost) {
            dp[r2][c2] = dp[r1][c1] + cost;
            parent[r2][c2] = mp(r1, c1);
        }
    };
    for (int i = 1; i <= A; i++) {
        for (int j = 1; j <= B; j++) {
            if (a[i - 1] == b[j - 1]) {
                maxi(i - 1, j - 1, i, j, 1);
            } else {
                maxi(i - 1, j, i, j, 0);
                maxi(i, j - 1, i, j, 0);
            }
        }
    }
    cout << dp[A][B] << endl;
    v<int> res;
    int r = A, c = B;
    debug(parent);
    while (r > 0 || c > 0) {
        auto [prev_r, prev_c] = parent[r][c];
        if (prev_r + 1 == r && prev_c + 1 == c && a[prev_r] == b[prev_c]) {
            res.pb(a[prev_r]);
        }
        r = prev_r, c = prev_c;
    }
    debug(res);
    for (int i = len(res) - 1; i >= 0; i--) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
