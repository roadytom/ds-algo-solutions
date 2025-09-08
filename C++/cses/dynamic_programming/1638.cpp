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
    int n;
    cin >> n;
    v<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    if (grid[0][0] == '*') {
        cout << 0 << endl;
        return;
    }
    v<v<mint> > dp(n + 1, v<mint>(n + 1));
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (grid[i - 1][j - 1] != '*') {
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    cout << dp[n][n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
