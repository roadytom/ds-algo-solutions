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
// #define endl "\n"
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
/**

*/
class Solution {
public:
    vector<vector<int> > reverseSubmatrix(vector<vector<int> > &grid, int r, int c, int k) {
        for (int i = r, j = r + k - 1; i != j; i++, j--) {
            for (int z = c; z < c + k; z++) {
                swap(grid[i][z], grid[j][z]);
            }
        }
        return grid;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    vector<vector<int> > grid =
    {
        {
            3, 4, 2, 3
        },
        {
            2, 3, 4, 2
        }
    };
    debug(s.reverseSubmatrix(grid, 0, 2, 2));
    return 0;
}
