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
    string s, l, r;
    int m;

    cin >> s;
    cin >> m;
    cin >> l >> r;
    int n = (int) s.size();
    int first_unchecked_idx = 0;
    for (int i = 0; i < m; i++) {
        int min_digit = l[i] - '0';
        int max_digit = r[i] - '0';
        int new_first_unchecked_idx = first_unchecked_idx;
        for (int digit = min_digit; digit <= max_digit; digit++) {
            int curr = first_unchecked_idx;
            while (curr < n && (s[curr] - '0') != digit) {
                curr++;
            }
            new_first_unchecked_idx = max(new_first_unchecked_idx, curr);
        }
        first_unchecked_idx = new_first_unchecked_idx + 1;
    }
    if (first_unchecked_idx > n) cout << "YES" << endl;
    else cout << "NO" << endl;
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
