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
    int countSquares(v<v<int> > &mat) {
        int row = len(mat), col = len(mat[0]);
        v<v<int> > pref(row + 1, v<int>(col + 1));
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                for (int length = 1; length <= min(i + 1, j + 1); length++) {
                    int cnt = pref[i + 1][j + 1] - pref[i - length + 1][j + 1] - pref[i + 1][j - length + 1] + pref[
                                  i - length + 1][j - length + 1];
                    if (cnt == length * length) {
                        ans++;
                    }
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
    v<v<int> > mat{{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};
    debug(s.countSquares(mat));
    return 0;
}
