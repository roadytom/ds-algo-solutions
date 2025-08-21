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
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int half = n / 2;
    if (half == 0) {
        cout << 0 << endl;
        return;
    }
    vector<int> dp(2);
    dp[0] = 0;
    dp[1] = 0;
    rep(i, 1, half) {
        vector<int> new_dp(2, INT_MAX / 2);
        int left = a[i], right = a[n - i - 1];
        int prev_left = a[i - 1], prev_right = a[n - i];
        for (int swap = 0; swap < 2; swap++) {
            int prev_cost = dp[swap];
            if (swap) {
                int cost_no_swap = prev_cost + (left == prev_right) + (right == prev_left);
                new_dp[0] = min(new_dp[0], cost_no_swap);
                int cost_swap = prev_cost + (left == prev_left) + (right == prev_right);
                new_dp[1] = min(new_dp[1], cost_swap);
            } else {
                int cost_no_swap = prev_cost + (left == prev_left) + (right == prev_right);
                new_dp[0] = min(new_dp[0], cost_no_swap);
                int cost_swap = prev_cost + (left == prev_right) + (right == prev_left);
                new_dp[1] = min(new_dp[1], cost_swap);
            }
        }
        dp = new_dp;
    }
    debug(dp);
    int min_total_disturbance = INT_MAX / 2;
    if (n % 2 == 0) {
        for (auto cost: dp) {
            min_total_disturbance = min(min_total_disturbance, cost + (a[half] == a[half - 1]));
        }
    } else {
        int mid_val = a[half];
        for (auto cost: dp) {
            min_total_disturbance = min(min_total_disturbance,
                                        cost + (a[half - 1] == mid_val) + (mid_val == a[half + 1]));
        }
    }
    cout << min_total_disturbance << endl;
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
