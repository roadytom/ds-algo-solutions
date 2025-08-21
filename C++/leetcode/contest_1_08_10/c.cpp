#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
/**

*/
class Solution {
public:
    long long maxTotal(vector<int> &value, vector<int> &limit) {
        int n = (int) value.size();
        vector<pair<int, int> > limit_values;
        for (int i = 0; i < n; i++) {
            limit_values.emplace_back(limit[i], value[i]);
        }
        sort(all(limit_values), [](const auto &a, const auto &b) {
            if (a.first - b.first != 0) return a.first < b.first;
            return b.second < a.second;
        });
        int active = 0;
        priority_queue<int, vector<int>, greater<int> > pq;
        ll ans = 0;
        for (auto &[l, v]: limit_values) {
            if (active < l) {
                ans += v;
                pq.push(l);
                active++;
            }
            int removed = 0;
            while (!pq.empty() && pq.top() <= active) {
                pq.pop();
                removed++;
            }
            active -= removed;
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    vector<int> temp = {4, 2, 6};
    vector<int> temp1 = {1, 1, 1};
    debug(s.maxTotal(temp, temp1));
    return 0;
}
