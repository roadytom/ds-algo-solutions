/**
 * 417
 * https://leetcode.com/problems/
 */
#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

#define len(x) static_cast<int>((x).size())

// Constants
constexpr long long MOD = 1e9 + 7;
constexpr long long INF = 1e18;
constexpr long long MAXN = 2e6 + 5; // for factorial precomputation etc.

class Solution {
public:
    vector<vector<int> > pacificAtlantic(vector<vector<int> > &heights) {
        int r = heights.size(), c = heights[0].size();
        vector<vector<bool> > visited(r, vector<bool>(c, false));
        vector<vector<array<bool, 2> > > touches(r, vector<array<bool, 2> >(c, {false, false}));
        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        auto is_outside = [&](int i, int j) {
            return i < 0 || i >= r || j < 0 || j >= c;
        };
        auto dfs = [&](this auto &self, int i, int j, int idx) -> void {
            if (is_outside(i, j)) return;
            if (visited[i][j]) return;

            visited[i][j] = true;
            touches[i][j][idx] = true;
            for (auto &dr: dirs) {
                int new_i = i + dr[0];
                int new_j = j + dr[1];
                if (is_outside(new_i, new_j)) continue;
                if (heights[i][j] >= heights[new_i][new_j]) {
                    self(new_i, new_j, idx);
                }
            }
        };
        for (int j = 0; j < c; j++) {
            dfs(0, j, 0);
        }
        for (int i = 0; i < r; i++) {
            dfs(i, 0, 0);
        }
        visited = vector<vector<bool> >(r, vector<bool>(c, false));
        for (int j = 0; j < c; j++) {
            dfs(r - 1, j, 1);
        }
        for (int i = 0; i < r; i++) {
            dfs(i, c - 1, 1);
        }
        vector<vector<int> > ans;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                auto &status = touches[i][j];
                if (status[0] && status[1]) {
                    ans.push_back(vector<int>{i, j});
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

    Solution sol;
    vector<vector<int> > grid = {
        {1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {
            6, 7, 1, 4, 5
        },
        {
            5, 1, 1, 2, 4
        }
    };
    debug(sol.pacificAtlantic(grid));
    // vector<int> temp{1, 2};
    // debug(sol.method(temp));

    return 0;
}
