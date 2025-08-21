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
    int n, k, q;
    cin >> n >> k >> q;
    vector<vector<int> > matrix(k, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> matrix[j][i];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < k; j++) {
            matrix[j][i] = matrix[j][i] | matrix[j][i - 1];
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < k; j++) {
    //         cout << matrix[j][i] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    while (q--) {
        int m;
        cin >> m;
        int left = 0, right = n - 1;
        while (m--) {
            int r, c;
            char o;
            cin >> r >> o >> c;
            r--;
            auto &regions = matrix[r];
            if (o == '<') {
                int larger_or_equal_idx = lower_bound(all(regions), c) - regions.begin() - 1;
                right = min(right, larger_or_equal_idx);
            } else {
                int greater_idx = upper_bound(all(regions), c) - regions.begin();
                left = max(left, greater_idx);
            }
        }
        if (left > right) cout << -1 << endl;
        else cout << left + 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
