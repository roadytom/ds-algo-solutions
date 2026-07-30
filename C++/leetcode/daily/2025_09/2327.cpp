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

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        // total, just knows
        v<pair<mint, mint>> dp(n + 1);
        dp[1] = {1, 1};
        for (int i = 2; i <= n; i++) {
            int start_day = max(0, i - forget + 1);
            int end_day = max(0, i - delay);
            debug(i, start_day, end_day);
            mint total = 0;
            mint just_knows = 0;
            for (int day = start_day; day <= end_day; day++) {
                just_knows += dp[day].s;
            }
            for (int day = end_day + 1; day < i; day++) {
                total += dp[day].s;
            }
            dp[i] = {total + 2 * just_knows, just_knows};
        }
        debug(dp);
        return dp[n].f.val();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    debug(s.peopleAwareOfSecret(6, 2, 4));
    return 0;
}
