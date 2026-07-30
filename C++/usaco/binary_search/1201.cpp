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
    v<ll> arr(n);
    rep(i, 0, n) cin >> arr[i];
    sort(all(arr));
    ll res = arr[n / 2];
    // arr.pb(INT_MAX / 2);
    debug(arr);
    for (int i = n / 2; i < n - 1 && k > 0; i++) {
        ll gain = (arr[i + 1] - arr[i]) * (i - n / 2 + 1);
        ll plus = min(k, gain);
        k -= plus;
        res += plus / (i - n / 2 + 1);
        debug(arr[i], plus, res, k);
    }
    res += k / (n - n / 2);
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
