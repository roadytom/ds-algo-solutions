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
    int n, m;
    cin >> n >> m;
    vector<int> a(n - 1), b(n);
    for (int i = 0; i < n - 1; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    a.push_back(1);
    sort(all(a));
    sort(all(b));
    int first = 0, second = 0;
    int match_count = 0;
    debug(a); debug(b);
    while (first < n && second < n) {
        if (a[first] < b[second]) {
            first++;
            second++;
            match_count++;
        } else {
            second++;
        }
    }
    cout << n - match_count << endl;
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
