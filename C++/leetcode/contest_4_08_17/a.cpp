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
    ll maxProfit(vector<int> &prices, vector<int> &strategy, int k) {
        int n = len(prices);
        v<ll> prefix_sum(n + 1);
        for (int i = 1; i <= n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + prices[i - 1] * strategy[i - 1];
        }
        int left = 0, right = 0;
        ll window_sum = 0;
        ll max_gain = 0;
        while (right < n) {
            window_sum += prices[right];
            if (right >= k - 1) {
                max_gain = max(max_gain, window_sum - prefix_sum[right + 1] + prefix_sum[right - k + 1]);
            }
            if ((right - left + 1) >= k / 2) {
                window_sum -= prices[left];
                left++;
            }
            right++;
        }
        return prefix_sum[n] + max_gain;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    v<int> prices{4, 2, 8};
    v<int> strategy{-1, 0, 1};
    int k = 2;
    debug(s.maxProfit(prices, strategy, k));
    return 0;
}
