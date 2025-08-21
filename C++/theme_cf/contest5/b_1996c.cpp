
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
    string a, b;
    cin >> a >> b;
    vector<vector<int> > prefix_countera(n + 1, vector<int>(26));
    vector<vector<int> > prefix_counterb(n + 1, vector<int>(26));
    rep(i, 1, n + 1) {
        rep(c, 0, 26) {
            prefix_countera[i][c] += prefix_countera[i - 1][c];
            prefix_counterb[i][c] += prefix_counterb[i - 1][c];
        }
        prefix_countera[i][a[i - 1] - 'a']++;
        prefix_counterb[i][b[i - 1] - 'a']++;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int ans = 0;
        rep(c, 0, 26) {
            int a_count = prefix_countera[r + 1][c] - prefix_countera[l][c];
            int b_count = prefix_counterb[r + 1][c] - prefix_counterb[l][c];
            ans += max(0, b_count - a_count);
        }
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
