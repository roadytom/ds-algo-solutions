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
    vector<vector<int> > activities(n, vector<int>(3, 0));
    const int inf = INT_MIN / 2;
    vector<vector<int> > dp(n + 1, vector<int>(3, inf));
    dp[0] = {0, 0, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> activities[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int curr = 0; curr < 3; curr++) {
            for (int prev = 0; prev < 3; prev++) {
                if (curr == prev) continue;
                dp[i][curr] = max(dp[i][curr], dp[i - 1][prev] + activities[i - 1][curr]);
            }
        }
    }
    cout << *max_element(all(dp[n])) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
