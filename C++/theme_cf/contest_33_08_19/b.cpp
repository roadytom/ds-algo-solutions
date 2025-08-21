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
    ll x, y;
    cin >> x >> y;
    v<ll> arr(n);
    rep(i, 0, n) cin >> arr[i];
    ll sum = accumulate(all(arr), 0LL);
    sort(all(arr));
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        auto left = lower_bound(arr.begin(), arr.begin() + i, sum - y - arr[i]) - arr.begin();
        auto right = upper_bound(arr.begin(), arr.begin() + i, sum - x - arr[i]) - arr.begin();
        ans += right - left;
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
