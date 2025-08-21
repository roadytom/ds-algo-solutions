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
    vector<int> arr(n + 1);
    vector<int> end;
    vector<int> start;
    rep(i, 1, n + 1) {
        cin >> arr[i];
    }
    int left = 1, right = 1;
    while (right <= n + 1) {
        if (right == (n + 1) || arr[right] != arr[left]) {
            start.push_back(left);
            end.push_back(right - 1);
            left = right;
        }
        right++;
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        auto it = upper_bound(all(start), l);
        int idx = it - start.begin();
        int curr_left = start[idx - 1];
        int curr_right = end[idx - 1];
        if (curr_left <= l && r <= curr_right) {
            cout << -1 << " " << -1 << endl;
        } else {
            cout << l << " " << curr_right + 1 << endl;
        }
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
