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
    v<int> nums{};

    int counter(int n, int prefix1, int prefix2) {
        int cnt = 0;
        while (prefix1 <= n) {
            cnt += min(n + 1, prefix2) - prefix1;
            prefix1 *= 10;
            prefix2 *= 10;
        }
        return cnt;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k) {
            int cnt = counter(n, curr, curr + 1);
            if (k >= cnt) {
                k -= cnt;
                curr = curr + 1;
            } else {
                k--;
                curr = 10 * curr;
            }
        }
        return curr;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    debug(s.findKthNumber(13, 2));
    return 0;
}
