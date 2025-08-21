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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> counter;
    rep(i, 0, n) {
        int x;
        cin >> x;
        a[i] = x;
        counter[x]++;
    }
    vector<int> counts;
    for (auto &[_, val]: counter) {
        counts.push_back(val);
    }
    sort(all(counts));
    int ans = 0;
    for (int count: counts) {
        if (k >= count) {
            k -= count;
        } else {
            ans++;
        }
    }
    ans = max(1, ans);
    cout << ans << endl;
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
