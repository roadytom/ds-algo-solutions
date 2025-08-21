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
using fourd = vector<vector<vector<vector<int> > > >;
using threed = vector<vector<vector<int> > >;
using twod = vector<vector<int> >;

class Solution {
public:
    int n;
    const int inf = INT_MAX / 2;

    bool check(int r, int c) const {
        return r >= 0 && r < n && c >= 0 && c < n;
    }

    int dp(fourd &memo, twod &grid, int r1, int c1, int r2, int c2) {
        if (!check(r1, c1) || !check(r2, c2)) {
            return -inf;
        }
        if (grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return -inf;
        }
        if (r1 == n - 1 && c1 == n - 1) {
            return grid[r1][c1];
        }
        int score = grid[r1][c1];
        if (r1 != r2 || c1 != c2) {
            score += grid[r2][c2];
        }
        return max(max(dp(memo, grid, r1, c1 + 1, r2, c2 + 1),
                       dp(memo, grid, r1, c1 + 1, r2 + 1, c2)),
                   max(
                       dp(memo, grid, r1 + 1, c1, r2, c2 + 1),
                       dp(memo, grid, r1 + 1, c1, r2 + 1, c2))) + score;
    }

    int cherryPickup(vector<vector<int> > &grid) {
        n = (int) grid.size();

        fourd memo(n, threed(n, twod(n, vector<int>(n))));
        return dp(memo, grid, 0, 0, 0, 0);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    twod grid(3);
    grid[0] = {0, 1, -1};
    grid[1] = {1, 0, -1};
    grid[2] = {1, 1, 1};
    debug(s.cherryPickup(grid));
    return 0;
}
