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
    int numSubmat(v<v<int> > &mat) {
        int R = len(mat), C = len(mat[0]);
        v<v<int> > prefix(R + 1, v<int>(C));
        for (int col = 0; col < C; col++) {
            for (int row = 0; row < R; row++) {
                if (mat[row][col] != 0) {
                    prefix[row + 1][col] = prefix[row][col] + mat[row][col];
                }
            }
        }
        int ans = 0;
        debug(prefix);
        v<v<int> > dp(R, v<int>(C));
        for (int i = 0; i < R; i++) {
            stack<int> st;
            auto &row_prefix = prefix[i + 1];
            for (int j = 0; j < C; j++) {
                while (!st.empty() && row_prefix[st.top()] > row_prefix[j]) {
                    st.pop();
                }
                int curr_sum = 0;
                if (!st.empty()) {
                    int left_idx = st.top();
                    curr_sum += row_prefix[j] * (j - left_idx);
                    curr_sum += dp[i][left_idx];
                } else {
                    int left_idx = -1;
                    curr_sum += row_prefix[j] * (j - left_idx);
                }
                ans += curr_sum;
                dp[i][j] = curr_sum;
                // for (int k = j; k >= 0 && min_length > 0; k--) {
                //     // if (mat[i][k] == 0) break;
                //     min_length = min(min_length, prefix[i + 1][k]);
                //     ans += min_length;
                // }
                st.push(j);
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
    v<v<int> > temp{{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};
    debug(s.numSubmat(temp));
    return 0;
}
