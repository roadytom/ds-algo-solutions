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
    int minimumSumSolve(v<v<int> > &mat) {
        int R = len(mat), C = len(mat[0]);
        int min_area = R * C;
        auto find_area = [&](int r1, int c1, int r2, int c2) {
            int min_row = INT_MAX;
            int min_col = INT_MAX;
            int max_row = INT_MIN;
            int max_col = INT_MIN;
            bool updated = false;
            for (int i = r1; i <= r2; i++) {
                for (int j = c1; j <= c2; j++) {
                    if (mat[i][j] == 1) {
                        min_row = min(min_row, i);
                        max_row = max(max_row, i);
                        min_col = min(min_col, j);
                        max_col = max(max_col, j);
                        updated = true;
                    }
                }
            }
            if (!updated) {
                return 1;
            }
            return (max_row - min_row + 1) * (max_col - min_col + 1);
        };
        auto find_area_2 = [&](int r1, int c1, int r2, int c2) {
            int min_area_2 = INT_MAX;
            for (int i = r1; i < r2; i++) {
                int first = find_area(r1, c1, i, c2);
                int second = find_area(i + 1, c1, r2, c2);
                min_area_2 = min(min_area_2, first + second);
            }
            for (int j = c1; j < c2; j++) {
                int first = find_area(r1, c1, r2, j);
                int second = find_area(r1, j + 1, r2, c2);
                min_area_2 = min(min_area_2, first + second);
            }
            return min_area_2;
        };
        for (int i = 0; i <= C - 2; i++) {
            int first = find_area(0, 0, R - 1, i);
            int second = find_area_2(0, i + 1, R - 1, C - 1);
            min_area = min(min_area, first + second);
        }

        for (int i = 0; i <= R - 2; i++) {
            int first = find_area(0, 0, i, C - 1);
            int second = find_area_2(i + 1, 0, R - 1, C - 1);
            min_area = min(min_area, first + second);
        }
        return min_area;
    }

    int minimumSum(v<v<int> > &mat) {
        int first = minimumSumSolve(mat);
        int n = len(mat), m = len(mat[0]);
        vector<vector<int> > reversed = mat;
        for (int i = 0; i < n; i++) {
            reverse(all(reversed[i]));
        }
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n / 2; i++) {
                swap(reversed[i][j], reversed[n - i - 1][j]);
            }
        }
        debug(reversed);

        return min(first, minimumSumSolve(reversed));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    v<v<int> > temp{{1, 1}, {1, 0}};
    debug(s.minimumSum(temp));
    return 0;
}
