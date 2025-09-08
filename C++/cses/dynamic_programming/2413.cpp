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
const int MAXN = 1e6 + 5;
v<v<mint> > dp(MAXN + 1, v<mint>(2, 0));

void solve() {
    // dp[i][state] -> num ways to achieve height i, state
    dp[0][1] = dp[0][0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        dp[i][0] = dp[i - 1][1] + 2 * dp[i - 1][0];
        dp[i][1] = 4 * dp[i - 1][1] + dp[i - 1][0];
    }
    // cout << dp[n - 1][0] + dp[n - 1][1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    solve();

    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        cout << dp[n - 1][0] + dp[n - 1][1] << endl;
    }
    return 0;
}
