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
using vi = v<int>;
/**

*/
class Solution {
public:
    int longestSubarray(v<int> &arr) {
        v<int> segment_count;
        int idx = 0;
        if (arr[0] == 0) {
            segment_count.pb(0);
        }
        while (idx < len(arr) && arr[idx] != 1) idx++;
        while (idx < len(arr)) {
            int cnt = 0;
            while (idx < len(arr) && arr[idx] != 0) {
                idx++;
                cnt++;
            }
            segment_count.pb(cnt);
            if (idx >= len(arr)) break;
            int zero_count = 0;
            while (idx < len(arr) && arr[idx] != 1) {
                idx++;
                zero_count++;
            }
            if (zero_count > 1) {
                segment_count.pb(0);
            }
        }
        if (len(segment_count) == 1) {
            return segment_count[0] == 0 ? 0 : segment_count[0] - 1;
        }
        int max_double = 0;
        for (int i = 1; i < len(segment_count); i++) {
            max_double = max(max_double, segment_count[i] + segment_count[i - 1]);
        }
        return max_double;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    v<int> temp{0, 1, 1, 1, 0, 1, 1, 0, 1};
    debug(s.longestSubarray(temp));
    return 0;
}
