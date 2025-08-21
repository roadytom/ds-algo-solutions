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
void solve() {
    string s, t;
    cin >> s >> t;
    int sy = s[1] - '1';
    int sx = s[0] - 'a';
    int ty = t[1] - '1';
    int tx = t[0] - 'a';
    // R -> x + 1, L -> x - 1;
    // U -> y + 1, D -> y - 1
    // x, y
    vector<pair<int, int> > drs{{1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<string> sign{"RU", "RD", "LU", "LD", "U", "R", "L", "D"};
    int moves = 0;
    vector<string> operations;
    debug(sx, sy);
    debug(tx, ty);
    while (sx != tx || sy != ty) {
        for (int i = 0; i < 8; i++) {
            auto [x, y] = drs[i];
            int new_x = sx + x;
            int new_y = sy + y;
            debug(new_x, new_y);
            if (abs(new_x - tx) <= abs(sx - tx) && abs(new_y - ty) <= abs(sy - ty)) {
                debug(new_x, new_y);
                debug(i, sign[i]);
                sx = new_x;
                sy = new_y;
                moves++;
                operations.push_back(sign[i]);
                break;
            }
        }
    }
    cout << moves << endl;
    for (auto &ss: operations) {
        cout << ss << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
