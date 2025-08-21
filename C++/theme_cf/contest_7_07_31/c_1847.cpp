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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int max_val = (1 << 8) - 1;
    for (int target = max_val; target >= 0; target--) {
        vector<bool> seen(1 << 8, false);
        seen[0] = true;
        int prefix_xor = 0;
        bool found = false;
        for (int j = 0; j < n; j++) {
            prefix_xor ^= a[j];
            int req = target ^ prefix_xor;
            if (seen[req]) {
                found = true;
                break;
            }
            seen[prefix_xor] = true;
        }
        if (found) {
            cout << target << endl;
            return;
        }
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
