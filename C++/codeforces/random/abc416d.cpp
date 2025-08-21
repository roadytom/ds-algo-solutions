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
/**

*/

int find_min_mod(int val, multiset<int> &mods) {
    auto it = mods.lower_bound(val);
    return 1;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    v<ll> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    sort(all(a)), sort(rall(b));
    ll c = 0;
    for (int i = 0, j = 0; i < n && j < n;) {
        if (a[i] + b[j] < m) {
            i++;
        } else {
            c++;
            i++;
            j++;
        }
    }
    ll a_sum = accumulate(all(a), 0LL);
    ll b_sum = accumulate(all(b), 0LL);
    cout << a_sum + b_sum - c * m << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
