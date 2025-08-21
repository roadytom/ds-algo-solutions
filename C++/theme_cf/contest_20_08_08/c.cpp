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
    int n, x;
    cin >> n >> x;
    vector<pair<int, int> > a(n), b(n);
    vector<pair<int, int> > original_a(n), original_b(n);
    rep(i, 0, n) {
        cin >> original_a[i].first;
        original_a[i].second = i;
    }
    rep(i, 0, n) {
        cin >> original_b[i].first;
        original_b[i].second = i;
    }
    a = original_a;
    b = original_b;
    sort(all(a));
    sort(all(b));
    vector<pair<int, int> > matching_pair;
    for (int i = 0; i < x; i++) {
        if (a[n - x + i].first <= b[i].first) {
            cout << "NO" << endl;
            return;
        } else {
            matching_pair.emplace_back(a[n - x + i].second, b[i].second);
        }
    }
    for (int i = x; i < n; i++) {
        if (a[i - x].first > b[i].first) {
            cout << "NO" << endl;
            return;
        } else {
            matching_pair.emplace_back(a[i - x].second, b[i].second);
        }
    }
    assert(matching_pair.size() == n);
    sort(all(matching_pair));
    cout << "YES" << endl;
    for (auto &[a_i, b_i]: matching_pair) {
        cout << original_b[b_i].first << " ";
    }
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
