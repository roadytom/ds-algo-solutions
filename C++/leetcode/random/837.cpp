#include <bits/stdc++.h>
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
class Solution {
public:
    double new21Game(int n, int k, int mx) {
        v<double> dp(n + 2);
        int left = 0, right = 1;
        double window_sum = k > 0;
        dp[0] = 1.0;
        while (right <= n) {
            dp[right] = window_sum / mx;
            if (right < k) {
                window_sum += dp[right];
            }
            if (right - left + 1 > mx && left < k) {
                window_sum -= dp[left];
                left++;
            }
            right++;
        }
        debug(dp);
        return accumulate(dp.begin() + k, dp.end(), 0.0);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    debug(s.new21Game(21, 17, 10));
    return 0;
}
