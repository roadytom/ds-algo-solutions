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
    string s1, s2;
    cin >> s1 >> s2;
    int n = len(s1), m = len(s2);
    // dp[i][j] -> edit distance transform two strings 0..i, 0..j
    v<v<int> > memo(n + 1, v<int>(m + 1, -1));
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         if (s1[i - 1] == s2[j - 1]) {
    //             dp[i][j] = dp[i - 1][j - 1];
    //         } else {
    //             dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
    //         }
    //     }
    // }
    function<int(int, int)> dp = [&](int i, int j) {
        if (i == n) return m - j;
        if (j == m) return n - i;
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        if (s1[i] == s2[j]) return memo[i][j] = dp(i + 1, j + 1);
        return memo[i][j] = min({dp(i + 1, j), dp(i, j + 1), dp(i + 1, j + 1)}) + 1;
    };
    cout << dp(0, 0) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
