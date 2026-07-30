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
    // dp[first_set_sum][idx] -> number of ways to achieve first_set_sum for the num 0..idx, decide for idx
    // dp[0][0] = 1;
    int n;
    cin >> n;
    int max_sum = (1 + n) * n / 2;
    if (max_sum % 2 != 0) {
        cout << 0 << endl;
        return;
    }
    max_sum /= 2;
    debug(max_sum);
    v<mint> dp(max_sum + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int sum = max_sum - i; sum >= 0; sum--) {
            dp[sum + i] += dp[sum];
        }
    }
    cout << dp[max_sum] / 2 << endl;
    debug(dp);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
