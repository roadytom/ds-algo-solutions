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
    int xorAfterQueries(vector<int> &nums, vector<vector<int> > &queries) {
        int n = len(nums);
        v<mint> arr(n);
        rep(i, 0, n) arr[i] = nums[i];
        for (auto &query: queries) {
            int l = query[0];
            int r = query[1];
            int k = query[2];
            int val = query[3];
            for (int i = l; i <= r; i += k) {
                arr[i] *= val;
            }
        }
        int x = 0;
        for (auto &val: arr) {
            x ^= val.val();
        }
        return x;
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
