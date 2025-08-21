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
/**

*/
class Solution {
public:
    int maxBalancedShipments(vector<int> &w) {
        int n = len(w);
        int left = 0, right = 0;
        int window_max = -1;
        int cnt = 0;
        while (right < n) {
            if (right - left + 1 > 1 && w[right] < window_max) {
                cnt++;
                left = right;
                window_max = -1;
            } else {
                window_max = max(window_max, w[right]);
            }
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
    v<int> wegiht{4,4};
    debug(s.maxBalancedShipments(wegiht));
    return 0;
}
