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
    vector<int> p(n);
    rep(i, 0, n) cin >> p[i];
    int min_val = INT_MAX;
    int min_winning_val = INT_MAX;
    int count = 0;
    rep(i, 0, n) {
        if (min_val < p[i] && min_winning_val > p[i]) {
            count++;
            min_winning_val = p[i];
        }
        min_val = min(min_val, p[i]);
    }

    cout << count << endl;
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
