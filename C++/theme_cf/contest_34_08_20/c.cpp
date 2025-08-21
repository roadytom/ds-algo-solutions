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
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define v vector
#define len(x) static_cast<int>((x).size())

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
    v<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(all(a));
    debug(a);

    ll left = 1, right = 2e12 + 5;
    auto get = [&](ll m, ll coin) {
        for (auto val: a) {
            if (val > m) continue;
            coin -= (m - val);
            if (coin < 0) return false;
        }
        return true;
    };
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (get(mid, k)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    ll target = right;
    int equal_right_length = 0;
    for (auto val: a) {
        if (val > target) continue;
        equal_right_length++;
        k -= (target - val);
    }
    debug(right);
    ll ans = right * n + (n - equal_right_length + k) - n + 1;
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
