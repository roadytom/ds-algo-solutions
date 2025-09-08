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
    void add(int r, int c, bool rev, v<int> &res, v<v<int> > &mat) {
        if (rev) {
            stack<int> st;
            do {
                st.push(mat[r][c]);
                r += 1;
                c -= 1;
            } while (r >= 0 && r < len(mat) && c >= 0 && c < len(mat[0]));
            while (!st.empty()) {
                res.pb(st.top());
                st.pop();
            }
        } else {
            do {
                res.pb(mat[r][c]);
                r += 1;
                c -= 1;
            } while (r >= 0 && r < len(mat) && c >= 0 && c < len(mat[0]));
        }
    }

    v<int> findDiagonalOrder(v<v<int> > &mat) {
        int R = len(mat), C = len(mat[0]);
        bool rev = true;
        v<int> res;
        for (int i = 0; i < C; i++) {
            add(0, i, rev, res, mat);
            rev ^= true;
        }
        for (int i = 1; i < R; i++) {
            add(i, C - 1, rev, res, mat);
            rev ^= true;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    v<v<int> > temp{{2, 5}, {8, 4}, {0, -1}};
    debug(s.findDiagonalOrder(temp));
    return 0;
}
