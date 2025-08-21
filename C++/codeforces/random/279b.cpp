#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
#define mp make_pair

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
/**

*/
void solve1() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<int> prefix_sum(n + 1);
    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    }
    int max_count = 0;
    debug(prefix_sum);
    for (int i = 0; i < n; i++) {
        int target = t + prefix_sum[i];
        int idx = (int) (upper_bound(prefix_sum.begin() + i, prefix_sum.end(), target) - prefix_sum.begin());
        int cnt = idx - i - 1;
        if (idx == n) {
            target = t - (prefix_sum[n] - prefix_sum[i]);
            auto it = upper_bound(prefix_sum.begin(), prefix_sum.end(), target) - prefix_sum.begin();
            cnt += (int) it;
        }
        max_count = max(max_count, min(n, cnt));
        debug(i, max_count);
    }
    cout << max_count << endl;
}

void solve() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    int left = 0, right = 0;
    int window_sum = 0;
    int ans = 0;
    while (right < n) {
        window_sum += a[right];
        while (left <= right && window_sum > t) {
            window_sum -= a[left];
            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
