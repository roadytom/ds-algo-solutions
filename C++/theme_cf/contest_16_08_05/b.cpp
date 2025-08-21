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
    int n;
    cin >> n;
    vector<int> c(n);
    rep(i, 0, n) cin >> c[i];
    sort(all(c));
    if (c[0] != 1 || (n > 1 && c[1] != 1)) {
        return false;
    }
    ll prev_sum = 2;
    for (int i = 2; i < n; i++) {
        int curr = c[i];
        if (curr > prev_sum) return false;
        prev_sum += curr;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        if (solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
