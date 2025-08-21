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
state:
dp[end][val] -> max num of segments that can be obtained on the range [0..end] and val

*/

// [start: end) start-> first non_zero, end-> next_zero or end of the array
ll process(int start, int end, vector<ll> &arr) {
    map<ll, ll> counter;
    ll prefix_sum = 0;
    ll ans = 1;
    counter[0] = 1;
    for (int i = start; i < end; i++) {
        prefix_sum += arr[i];
        counter[prefix_sum]++;
    }
    for (auto &[key, val]: counter) {
        ans = max(ans, val);
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    rep(i, 0, n) cin >> arr[i];
    ll prefix_sum = 0;
    ll ans = 0;
    int idx = 0;
    while (idx < n && arr[idx] != 0) {
        prefix_sum += arr[idx];
        if (prefix_sum == 0) {
            ans++;
        }
        idx++;
    }
    while (idx < n) {
        int start = idx + 1;
        idx++;
        while (idx < n && arr[idx] != 0) {
            idx++;
        }
        ans += process(start, idx, arr);
    }
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
