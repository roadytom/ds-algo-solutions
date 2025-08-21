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
    ll n, q;
    cin >> n >> q;
    v<ll> locations(n);
    rep(i, 0, n) cin >> locations[i];
    sort(all(locations));
    while (q--) {
        ll l, r;
        cin >> l >> r;
        auto left = lower_bound(all(locations), l) - locations.begin();
        auto right = upper_bound(all(locations), r) - locations.begin();
        if (left >= right) {
            cout << 0 << endl;
        } else {
            cout << right - left << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("haybales.in", "r", stdin); // read from input.txt
    freopen("haybales.out", "w", stdout); // write to output.txt
    solve();
    return 0;
}
