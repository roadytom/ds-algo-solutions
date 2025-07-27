#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007
#define INF LLONG_MAX

void solve() {
    ll n, s, x;
    cin >> n >> s >> x;
    vector<ll> arr(n);
    for (ll &a: arr) cin >> a;

    ll left = 0, right = 0;
    ll window_sum = 0;
    ll curr_max = LLONG_MIN;
    map<ll, vector<ll> > prefix_sum;
    prefix_sum[0].push_back(-1);

    ll ans = 0;
    ll right_most_max = -1;

    while (right < n) {
        window_sum += arr[right];
        if (arr[right] == x) {
            right_most_max = right;
        }
        curr_max = max(curr_max, arr[right]);

        if (curr_max == x) {
            ll target = window_sum - s;
            if (prefix_sum.count(target)) {
                auto &idxs = prefix_sum[target];
                // Count elements in range [left-1, right_most_max) using binary search
                ll cnt = lower_bound(idxs.begin(), idxs.end(), right_most_max) -
                          lower_bound(idxs.begin(), idxs.end(), left - 1);
                ans += cnt;
            }
        }
        prefix_sum[window_sum].push_back(right);

        if (curr_max > x) {
            // Reset for new window
            left = right + 1;
            curr_max = LLONG_MIN;
            window_sum = 0;
            right_most_max = -1;

            // Clear prefix_sum and reinitialize
            prefix_sum.clear();
            prefix_sum[0].push_back(right); // right is now the new "left-1"
        }
        ++right;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
