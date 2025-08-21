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
constexpr int INF = INT_MAX / 2;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    rep(i, 0, n) cin >> arr[i];
    // dp[i][j] -> min number of operations required to make product mod of [0..i] j
    vector<int> dp(k, INF);
    dp[1] = 0;
    rep(i, 0, n) {
        vector<int> new_dp(k, INF);
        rep(mod, 0, k) {
            if (dp[mod] == INF) continue;
            rep(operations, 0, k) {
                int num = arr[i] + operations;
                int new_mod = mod * num % k;
                new_dp[new_mod] = min(new_dp[new_mod], dp[mod] + operations);
            }
        }
        dp = new_dp;
    }
    cout << dp[0] << endl;
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
