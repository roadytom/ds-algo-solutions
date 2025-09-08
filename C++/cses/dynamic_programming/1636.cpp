#include <bits/stdc++.h>
#include <atcoder/modint>

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
using mint = atcoder::modint1000000007;

void solve() {
    int n, x;
    cin >> n >> x;
    v<int> coins(n);
    rep(i, 0, n) cin >> coins[i];
    v<mint> dp(x + 1, 0);
    dp[0] = 1;
    for (int coin: coins) {
        for (int i = 0; i < x; i++) {
            if (coin + i <= x) {
                dp[coin + i] += dp[i];
            }
        }
    }
    cout << dp[x] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
