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
    int numberOfPairs(vector<vector<int> > &x) {
        v<pii> points;
        for (auto &xx: x) {
            points.emplace_back(xx[0], xx[1]);
        }
        sort(all(points), [&](const auto &a, const auto &b) {
            if (a.f != b.f) {
                return a.f < b.f;
            }
            return a.s > b.s;
        });
        debug(points);
        int ans = 0;
        for (int i = 0; i < len(points); i++) {
            auto &[x1, y1] = points[i];
            int prev_max = -1;
            for (int j = i + 1; j < len(points); j++) {
                auto &[x2, y2] = points[j];
                if (y2 > prev_max && y2 <= y1) {
                    ans++;
                    prev_max = y2;
                }
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    v<v<int> > temp{{0, 0}, {0, 3}};
    debug(s.numberOfPairs(temp));
    return 0;
}
