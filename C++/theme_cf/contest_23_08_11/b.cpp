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
    if (a[n - 1] != 0) {
        cout << "NO" << endl;
        return;
    }
    vector<int> segments;
    int prev = -1;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (prev != a[i]) {
            if (prev != -1) segments.push_back(count);
            count = 0;
            prev = a[i];
        }
        count++;
    }
    segments.push_back(count);
    debug(segments);
    vector<int> ans;
    for (int i = (int) segments.size() - 1; i >= 0;) {
        int zero_count = segments[i];
        if (i == 0) {
            for (int j = 0; j < zero_count; j++) {
                ans.push_back(0);
            }
            break;
        }
        int one_count = segments[i - 1];
        for (int j = 0; j < zero_count - 1 + one_count; j++) {
            ans.push_back(0);
        }
        ans.push_back(one_count);
        i -= 2;
    }
    // reverse(all(ans));
    cout << "YES" << endl;
    for (auto &val: ans) {
        cout << val << " ";
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
