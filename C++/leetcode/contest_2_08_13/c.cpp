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
    int minTime(string s, vector<int> &order, int k) {
        int n = len(order);
        set<int> points;
        points.insert(-1);
        points.insert(n);
        ll total = 1LL * n * (n + 1) / 2;
        ll non_matching = total;
        for (int t = 0; t < n; t++) {
            int new_point = order[t];
            auto r = points.upper_bound(new_point);
            auto l = prev(r);
            ll count = (*r - *l - 1);
            ll old_non_matching = 1LL * count * (count + 1) / 2;
            non_matching -= old_non_matching;
            ll count1 = *r - new_point - 1;
            non_matching += 1LL * count1 * (count1 + 1) / 2;
            ll count2 = new_point - *l - 1;
            non_matching += 1LL * count2 * (count2 + 1) / 2;
            points.insert(new_point);
            if (total - non_matching >= k) return t;
        }
        return -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    string first = "cat";
    v<int> order = {0, 2, 1};
    debug(s.minTime(first, order, 6));
    return 0;
}
