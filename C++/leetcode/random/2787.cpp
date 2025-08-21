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

class Solution {
public:
    int numberOfWays(int n, int x) {
        vector<int> powers;
        int power = 1;
        int p = 1;
        while (power <= n) {
            powers.push_back(power);
            p++;
            power = (int) pow(p, x);
            // cout << power << endl;
        }
        // for (int p: powers) {
        //     cout << p << endl;
        // }
        vector<vector<mint> > memo(n + 1, vector<mint>((int) powers.size() + 1, -1));
        function<mint(int, int)> dp = [&](int num, int idx) -> mint {
            if (num == 0) return 1;
            if (idx >= (int) powers.size() || num < powers[idx]) return 0;
            if (memo[num][idx] != -1) return memo[num][idx];
            return memo[num][idx] = dp(num - powers[idx], idx + 1) + dp(num, idx + 1);
        };
        return dp(n, 0).val();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    debug(s.numberOfWays(213, 1));
    return 0;
}
