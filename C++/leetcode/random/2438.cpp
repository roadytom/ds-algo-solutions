#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/segtree>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
#define mp make_pair

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
/**

*/
using mint = atcoder::modint1000000007;
using S = mint;

// op: The function to combine two data values (S). We need the minimum.
S op(S a, S b) { return a * b; }
// e: The identity element for the op function.
S e() { return 1; }

class Solution {
public:
    bool get_bit(int num, int pos) {
        return num & (1 << pos);
    }

    vector<int> productQueries(int n, vector<vector<int> > &queries) {
        vector<mint> powers;
        for (int pos = 0; pos < 31; pos++) {
            if (get_bit(n, pos)) {
                powers.emplace_back(1LL << pos);
            }
        }
        debug(powers);
        atcoder::segtree<S, op, e> seg(powers);
        vector<int> ans;
        for (auto &query: queries) {
            int l = query[0], r = query[1];
            ans.push_back(seg.prod(l, r + 1).val());
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    vector<vector<int> > queries = {{0, 1}, {2, 2}, {0, 3}};
    debug(s.productQueries(15, queries));
    return 0;
}
