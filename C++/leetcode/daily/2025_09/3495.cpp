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
    ll find_count(ll n) {
        if (n == 0) return 0;
        ll pow = 1;
        ll ans = 0LL;
        ll cnt = 1;
        do {
            ll next = min(4 * pow - 1, n);
            ans += cnt * (next - pow + 1);
            // debug(next, pow, cnt * (next - pow + 1));
            debug(cnt * (next - pow + 1));
            pow = next + 1;
            cnt++;
        } while (pow < n);
        // debug((ans + 1) / 2);
        return ans;
    }

    ll minOperations(v<v<int> > &queries) {
        ll res = 0;
        for (auto &query: queries) {
            res += (find_count(query[1]) - find_count(query[0] - 1) + 1) / 2;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    v<v<int> > temp{{14, 18}};
    debug(s.minOperations(temp));
    return 0;
}
