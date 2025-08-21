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
    string x;
    cin >> x;
    vector<int> s;
    int n = (int) x.size();

    rep(i, 0, n) s.push_back(x[i] - '0');
    multiset<pair<int, int> > el_idx;
    rep(i, 0, n) el_idx.emplace(s[i], i);
    vector<int> res;
    int changed_idx = -1;
    rep(i, 0, n) {
        auto min_el = *el_idx.begin();
        el_idx.erase(el_idx.begin());
        res.push_back(min_el.first);
        rep(j, changed_idx + 1, min_el.second) {
            el_idx.erase(pair<int, int>{s[j], j});
            el_idx.emplace(min(9, s[j] + 1), j);
        }
        changed_idx = max(changed_idx, min_el.second);
    }
    rep(i, 0, n) cout << res[i];
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
