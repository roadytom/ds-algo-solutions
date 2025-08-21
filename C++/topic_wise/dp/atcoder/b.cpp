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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    const int inf = INT_MAX / 2;
    vector<int> dp(n, inf);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= i + k; j++) {
            if (j < n) {
                dp[j] = min(dp[j], dp[i] + abs(a[j] - a[i]));
            }
        }
    }
    cout << dp[n - 1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
