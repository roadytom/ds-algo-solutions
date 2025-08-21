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
    int n;
    cin >> n;
    ll k;
    cin >> k;
    v<int> a(n);
    rep(i, 0, n) cin >> a[i];
    v<ll> h(n);
    rep(i, 0, n) cin >> h[i];
    v<ll> prefix_sum(n + 1);
    partial_sum(all(a), prefix_sum.begin() + 1);
    v<ll> length(n, 1);
    for (int i = n - 2; i >= 0; i--) {
        if (h[i] % h[i + 1] == 0) {
            length[i] += length[i + 1];
        } else {
            length[i] = 1;
        }
    }
    ll left = 0, right = n;
    auto possible = [&](ll dist) {
        for (int i = 0; i < n - dist + 1; i++) {
            if (length[i] < dist) {
                continue;
            }
            ll r = i + dist;
            if (prefix_sum[r] - prefix_sum[i] <= k) {
                return true;
            }
        }
        return false;
    };
    debug(length);
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (possible(mid)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << right << endl;
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
