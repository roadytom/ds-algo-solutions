#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
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
const int INF = 1e9 + 5;

void solve() {
    int n;
    cin >> n;
    v<string> grid(n);
    rep(i, 0, n) cin >> grid[i];
    v<v<int> > dp(n + 1, v<int>(n + 1, INF));
    for (int diagonal = 2 * n - 2; diagonal >= 0; diagonal--) {
        v<pii> diagonal_coord;
        for (int row = 0; row < n; row++) {
            int col = diagonal - row;
            if (col >= 0 && col < n) {
                diagonal_coord.emplace_back(row, col);
            }
        }
        v<pair<int, int> > order(len(diagonal_coord)); // change here to make linear sorting e.g. radix sort

        for (int i = 0; i < len(diagonal_coord); i++) {
            auto &[r, c] = diagonal_coord[i];
            int nxt = min(dp[r + 1][c], dp[r][c + 1]);
            order[i] = mp((grid[r][c] - 'a') * (n + 1) + nxt, r);
        }
        sort(all(order));
        int id = 0;
        for (int i = 0; i < len(order); i++) {
            if (i == 0 || order[i].f != order[i - 1].f) {
                id++;
            }
            int r = order[i].s, c = diagonal - r;
            dp[r][c] = id;
        }
    }
    int r = 0, c = 0;
    cout << grid[r][c];
    while (r < n - 1 || c < n - 1) {
        if (dp[r + 1][c] < dp[r][c + 1]) {
            r++;
        } else {
            c++;
        }
        cout << grid[r][c];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
