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
    long long maxProduct(vector<int> &nums) {
        int k = (int)(log2(*max_element(all(nums)))) + 1;
        int mask = 1 << k;
        v<int> dp(mask, 0);
        for (int num: nums) {
            dp[num] = num;
        }
        for (int num: nums) {
            int req = (mask - 1) ^ num;
            for (int i = 0; i < mask; i++) {
                if ((req | i) <= req) {
                    dp[req] = max(dp[req], dp[i]);
                }
            }
        }
        ll res = LLONG_MIN;
        for (int num: nums) {
            int complement = (mask - 1) ^ num;
            res = max(res, 1LL * num * dp[complement]);
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    v<int> temp{64,8,32};
    debug(s.maxProduct(temp));
    return 0;
}
