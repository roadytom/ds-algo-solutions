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
#define len(x) static_cast<int>((x).size())
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define v vector

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
/**

*/
void solve() {
    int n, k;
    cin >> n >> k;
    v<ll> arr(n);
    rep(i, 0, n) cin >> arr[i];
    sort(all(arr));
    ll lo = 1, hi = 4e14;
    auto check = [&](ll presses) {
        ll total_gain = 0LL;
        for (int i = 0; i < n && presses > 0; i++) {
            ll curr = arr[i] - (i == 0 ? 0 : arr[i - 1]);
            ll gain = min(presses, curr * (n - i));
            total_gain += gain;
            presses -= gain;
            if (total_gain >= k) return true;
            // extra press to find if there is no lemonda left
            presses--;
        }
        return false;
    };
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << endl;
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
