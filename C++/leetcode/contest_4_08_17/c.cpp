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
    void set_min(map<int, pli> &map, int key, pli &&val) {
        if (map.count(key)) {
            map[key] = min(map[key], val);
        } else {
            map[key] = val;
        }
    }


    long long minArraySum(vector<int> &nums, int k) {
        int n = len(nums);
        v<ll> dp(n + 1);
        // dp[i] min sum after optimally deleting
        // transition: dp[i] = min(dp[i - 1] + nums[i], delete -> dp[map[mod]])
        dp[0] = 0;
        map<int, pli> mod_idx;
        mod_idx[0] = mp(0LL, 0);
        ll prefix_sum = 0LL;
        for (int i = 1; i <= n; i++) {
            prefix_sum += nums[i - 1];
            int rem = prefix_sum % k;

            dp[i] = dp[i - 1] + nums[i - 1];
            if (mod_idx.count(rem)) {
                dp[i] = min(dp[i], mod_idx[rem].f);
            }

            set_min(mod_idx, rem, mp(dp[i], i));
        }
        debug(mod_idx);
        debug(dp);
        return dp[n];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    v<int> nums{3,1,4,1,5};
    int k = 3;
    debug(s.minArraySum(nums, k));
    return 0;
}
