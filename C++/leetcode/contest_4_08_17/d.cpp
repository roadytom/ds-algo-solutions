#include <bits/stdc++.h>
#include <atcoder/modint.hpp>

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
    int xorAfterQueries(vector<int> &nums, vector<vector<int> > &queries) {
        int n = len(nums);
        v<mint> final_vals(n);
        rep(i, 0, n) final_vals[i] = nums[i];
        map<int, v<mint> > events;
        const int BLOCK = sqrt(1.0 * n) + 1;
        for (auto &q: queries) {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int val = q[3];
            if (k >= BLOCK) {
                for (int i = l; i <= r; i += k) {
                    final_vals[i] *= val;
                }
            } else {
                if (!events.count(k)) {
                    events[k] = v<mint>(n + 1, 1);
                }
                events[k][l] *= val;
                int r2 = l + (((r - l) / k) + 1) * k;
                events[k][min(r2, n)] /= val;
            }
        }
        for (auto &[k, event]: events) {
            for (int rem = 0; rem < k; rem++) {
                mint curr = 1;
                for (int i = rem; i < n; i += k) {
                    curr = curr * event[i];
                    final_vals[i] *= curr;
                }
            }
        }
        int ans = 0;
        for (auto &val: final_vals) {
            ans ^= val.val();
        }
        return ans;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    v<int> nums{1, 1, 1};
    v<v<int> > queries{{0, 2, 1, 4}};
    debug(s.xorAfterQueries(nums, queries));
    return 0;
}
