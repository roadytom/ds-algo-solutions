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


ll MAXN = (int) 1e6 + 1;
ll prefix_sum[1501][1501] = {};
ll ans[(int) 2e6 + 1] = {};

void fill_dp() {
    ll diagonal_length = 1;
    ll num = 1LL;
    while (num < MAXN) {
        ll row = diagonal_length;
        ll col = 0;
        rep(i, 0, diagonal_length) {
            if (num >= MAXN)
                break;
            prefix_sum[row + 1][col + 1] = prefix_sum[row][col + 1] + prefix_sum[row + 1][col] - prefix_sum[row][col] +
                                           num * num;
            ans[num] = prefix_sum[row + 1][col + 1];
            row -= 1;
            col += 1;
            num++;
        }
        diagonal_length++;
    }
}


void solve() {
    ll n;
    cin >> n;
    cout << 1LL * ans[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill_dp();

    int T;
    cin >> T;
    // debug(dp);
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
