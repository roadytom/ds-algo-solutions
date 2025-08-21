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
    ll perfectPairs(vector<int> &nums) {
        int n = len(nums);
        rep(i, 0, n) nums[i] = abs(nums[i]);
        sort(all(nums));
        int left = 0, right = 0;
        ll cnt = 0;
        while (right < n) {
            while (left <= right && 2 * nums[left] < nums[right]) {
                left++;
            }
            cnt += right - left;
            right++;
        }
        return cnt;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    v<int> temp{-3,2,-1,4};
    debug(s.perfectPairs(temp));
    return 0;
}
