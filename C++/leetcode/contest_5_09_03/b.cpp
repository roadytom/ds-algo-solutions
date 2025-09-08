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
    vector<int> minDifference(int n, int k) {
        int ans = INT_MAX;
        vector<int> *res;
        auto update_min = [&](vector<int> &curr) {
            int mn = *min_element(curr.begin(), curr.end());
            int mx = *max_element(curr.begin(), curr.end());
            if (ans > mx - mn) {
                ans = mx - mn;
                res = &curr;
            }
        };
        function<void(int, int, int, vector<int> &)> backtrack = [&](int num, int start, int picks, vector<int> &curr) {
            if (picks == 1) {
                if (num >= start) {
                    curr.push_back(num);
                    update_min(curr);
                    curr.pop_back();
                }
                return;
            }
            for (int i = start; i <= num; i++) {
                if (num % i == 0) {
                    curr.push_back(i);
                    backtrack(num / i, i, picks - 1, curr);
                    curr.pop_back();
                }
            }
        };
        vector<int> curr;
        backtrack(n, 1, k, curr);
        return *res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    debug(s.minDifference(100, 2));
    return 0;
}
