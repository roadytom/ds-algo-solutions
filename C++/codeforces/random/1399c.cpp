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
    vector<int> w(n);
    rep(i, 0, n) cin >> w[i];
    sort(all(w));
    int max_res = 0;
    for (int s = 2; s <= 2 * n; s++) {
        int left = 0, right = n - 1;
        int res = 0;
        while (left < right) {
            int sm = w[left] + w[right];
            if (sm == s) {
                res++;
                left++;
                right--;
            } else if (sm > s) {
                right--;
            } else {
                left++;
            }
        }
        max_res = max(max_res, res);
    }
    cout << max_res << endl;
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
