#include <atcoder/internal_type_traits.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
// Macros
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii std::pair<int, int>
#define vii std::vector<pii>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(x) static_cast<int>((x).size())
#define str(x) to_string(x)
#define list vector
#define dict map
#define print(x) cout << x << endl;
#define print10(x) cout << fixed << setprecision(10) << x << endl;
#define endl "\n"

// Constants
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;
constexpr ll MAXN = 2e6 + 5; // for factorial precomputation etc.


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
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
