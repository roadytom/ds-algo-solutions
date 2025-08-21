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
    int n, q;
    cin >> n >> q;
    vector<vector<int> > prefix_sum(n + 1, vector<int>(n + 1));
    rep(i, 1, n + 1) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
            if (s[j - 1] == '*') {
                prefix_sum[i][j]++;
            }
        }
    }
    // debug(prefix_sum);
    while (q--) {
        int col1, row1, col2, row2;
        cin >> row1 >> col1 >> row2 >> col2;
        cout << prefix_sum[row2][col2] - prefix_sum[row1 - 1][col2] - prefix_sum[row2][col1 - 1] + prefix_sum[row1 - 1][
            col1 - 1] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
