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
const ll inf = LLONG_MAX / 2;

void solve() {
    int N, M, L;
    cin >> N >> M >> L;
    v<int> a(N);
    rep(i, 0, N) cin >> a[i];
    v<v<ll> > f(L, v<ll>(M, 0));
    v<v<ll> > f2(L, v<ll>(M, 0));
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < M; j++) {
            int cost = 0;
            for (int k = i; k < N; k += L) {
                if (j >= a[k]) cost += j - a[k];
                else cost += j - a[k] + M;
            }
            f2[i][j] = cost;
        }
    }
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < M; j++) {
            ll cnt = 0;
            for (int k = i; k < N; k += L) {
                int curr = a[k];
                cnt += (j - curr + M) % M;
            }
            f[i][j] = cnt;
        }
    }
    debug(f);
    debug(f2);
    v<v<ll> > dp(L + 1, v<ll>(M, inf));
    for (int i = 0; i < M; i++) {
        dp[0][0] = 0;
    }
    for (int i = 1; i <= L; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < M; k++) {
                dp[i][(j + k) % M] = min(dp[i][(j + k) % M], dp[i - 1][j] + f[i - 1][k]);
            }
            // debug(dp[i]);
        }
    }
    // debug(dp);
    cout << dp[L][0] << endl;
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
