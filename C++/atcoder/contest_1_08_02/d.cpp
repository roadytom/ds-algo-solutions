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
    vector<int> p(n), a(n), b(n);
    rep(i, 0, n) {
        cin >> p[i] >> a[i] >> b[i];
    }
    const int M = 1010;
    vector<vector<int> > dp(n + 1, vector<int>(M));
    for (int mood = 0; mood < M; mood++) {
        dp[n][mood] = mood;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int mood = 0; mood < M; mood++) {
            if (mood <= p[i]) {
                dp[i][mood] = dp[i + 1][mood + a[i]];
            } else {
                dp[i][mood] = dp[i + 1][max(0, mood - b[i])];
            }
        }
    }
    vector<int> prefix_sum(n + 1);
    for (int i = 1; i <= n; i++) {
        prefix_sum[i] += prefix_sum[i - 1] + b[i - 1];
    }
    int q;
    cin >> q;
    // debug(dp);
    while (q--) {
        int initial_mood;
        cin >> initial_mood;
        auto idx = lower_bound(prefix_sum.begin(), prefix_sum.end() - 1, initial_mood - M + 1) - prefix_sum.begin();
        initial_mood -= prefix_sum[idx];
        if (idx == n) {
            cout << initial_mood << endl;
        } else {
            cout << dp[idx][initial_mood] << endl;
        }
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
