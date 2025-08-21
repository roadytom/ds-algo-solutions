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
bool solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> counter;
    vector<int> c(n);
    rep(i, 0, n) cin >> c[i];
    vector<int> prefix_sum(n + 1);
    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + (c[i] == c[0]);
    }
    if (c[0] == c[n - 1]) {
        if (prefix_sum[n] >= k) {
            return true;
        }
        return false;
    }
    int last_count = 0;
    for (int i = n - 1; i >= 0; i--) {
        last_count += c[i] == c[n - 1];
        int prev_count = prefix_sum[i];
        if (last_count >= k && prev_count >= k) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        if (solve()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
