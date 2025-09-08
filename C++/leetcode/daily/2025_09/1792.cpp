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
    struct ratio {
        int num;
        int denom;

        bool operator<(const ratio &other) const {
            double curr = 1.0 * num / denom;
            double new_curr = 1.0 * (num + 1) / (denom + 1);

            double ot = 1.0 * other.num / other.denom;
            double new_ot = 1.0 * (other.num + 1) / (other.denom + 1);
            return (new_curr - curr) < (new_ot - ot);
        }
    };

    double maxAverageRatio(vector<vector<int> > &classes, int extra) {
        priority_queue<ratio> ratios;
        for (auto &list: classes) {
            ratios.push({list[0], list[1]});
        }
        while (extra--) {
            auto [num, denom] = ratios.top();
            ratios.pop();
            ratios.push({num + 1, denom + 1});
        }
        double ans = 0;
        while (!ratios.empty()) {
            const auto &[num, denom] = ratios.top();
            ans += 1.0 * num / denom;
            ratios.pop();
        }
        ans /= len(classes);
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    v<v<int> > temp = {{1, 2}, {3, 5}, {2, 2}};
    debug(s.maxAverageRatio(temp, 2));
    return 0;
}
