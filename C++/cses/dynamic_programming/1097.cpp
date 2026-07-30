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
const ll INF = LLONG_MAX / 2;

void solve() {
    int n;
    cin >> n;
    v<ll> arr(n);
    rep(i, 0, n) cin >> arr[i];
    auto def = mp(-INF, -INF);
    v<v<pll> > memo(n, v<pll>(n, def));
    v<ll> prefix_sum(n + 1);
    partial_sum(all(arr), prefix_sum.begin() + 1);
    function<pll(int, int)> dp = [&](int l, int r) {
        if (l == r) {
            return mp(arr[l], 0LL);
        }
        if (memo[l][r] != def) {
            return memo[l][r];
        }
        ll me = max(arr[l] + dp(l + 1, r).s, arr[r] + dp(l, r - 1).s);
        ll he = prefix_sum[r + 1] - prefix_sum[l] - me;
        return memo[l][r] = {me, he};
    };
    ll res = dp(0, n - 1).f;
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
