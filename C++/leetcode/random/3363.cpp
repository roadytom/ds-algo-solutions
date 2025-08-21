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
#define endl "\n"
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
/**

*/
struct Data {
    int start_r, start_c;
    vector<pair<int, int> > drs;
};

class Solution {
public:
    int maxCollectedFruits(vector<vector<int> > &fruits) {
        int inf = INT_MAX / 2;
        int ans = 0;
        int n = (int) fruits.size();
        for (int i = 0; i < n; i++) {
            ans += fruits[i][i];
            fruits[i][i] = 0;
        }
        auto check = [&](int r, int c) {
            return r >= 0 && r < n && c >= 0 && c < n;
        };
        auto moves_count = [&](int r, int c, int start_r, int start_c) {
            return max(abs(start_r - r), abs(start_c - c)) + max(abs(n - 1 - r), abs(n - 1 - c));
        };
        vector<Data> children{
            Data{0, n - 1, {{1, -1}, {1, 0}, {1, 1}}},
            Data{n - 1, 0, {{-1, 1}, {0, 1}, {1, 1}}}
        };
        vector<vector<int> > memo(n, vector<int>(n, -1));
        function<int(int, int, int)> dp = [&](int r, int c, int child_id) {
            if (!check(r, c)) {
                return -inf;
            }
            if (r == n - 1 && c == n - 1) {
                return 0;
            }
            if (moves_count(r, c, children[child_id].start_r, children[child_id].start_c) > n - 1) {
                return -inf;
            }
            if (memo[r][c] != -1) {
                return memo[r][c];
            }
            int res = -inf;
            for (auto &[r_diff, c_diff]: children[child_id].drs) {
                int new_row = r + r_diff;
                int new_col = c + c_diff;
                res = max(res, dp(new_row, new_col, child_id));
            }
            return memo[r][c] = res + fruits[r][c];
        };
        int first_child = dp(children[0].start_r, children[0].start_c, 0);
        int second_child = dp(children[1].start_r, children[1].start_c, 1);
        debug(ans);
        debug(first_child);
        debug(second_child);

        return ans + first_child + second_child;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    vector<vector<int> > vec;
    vec.push_back({1, 2, 3, 4});
    vec.push_back({5, 6, 8, 7});
    vec.push_back({9, 10, 11, 12});
    vec.push_back({13, 14, 15, 16});
    debug(s.maxCollectedFruits(vec));
    return 0;
}
