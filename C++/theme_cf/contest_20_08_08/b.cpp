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
    map<int, int> counter;
    int n;
    cin >> n;
    rep(i, 0, n * (n - 1) / 2) {
        int x;
        cin >> x;
        counter[x]++;
    }
    vector<int> ans;
    int curr = n - 1;
    for (auto &[key, val]: counter) {
        while (val != 0) {
            ans.push_back(key);
            val -= curr;
            curr--;
        }
    }
    ans.push_back(counter.rbegin()->first);
    rep(i, 0, n) cout << ans[i] << " ";
    cout << endl;
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
