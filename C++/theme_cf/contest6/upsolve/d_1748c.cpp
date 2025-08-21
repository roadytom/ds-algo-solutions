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
    vector<ll> arr(n);
    rep(i, 0, n) cin >> arr[i];
    ll prefix_sum = 0;
    ll ans = 0;
    map<ll, ll> counter;
    ll max_freq = 0;
    bool zero_found = false;
    for (ll i = 0; i < n; i++) {
        if (arr[i] == 0) {
            if (zero_found) {
                ans += max_freq;
            } else {
                ans += counter[0];
            }
            zero_found = true;
            prefix_sum = 0;
            counter.clear();
            max_freq = 0;
        }
        prefix_sum += arr[i];
        counter[prefix_sum]++;
        max_freq = max(max_freq, counter[prefix_sum]);
    }
    if (zero_found) {
        ans += max_freq;
    } else {
        ans += counter[0];
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
