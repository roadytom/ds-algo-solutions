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
#define mp make_pair
#define pb push_back
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
using vl = vector<ll>;
using vb = vector<bool>;
/**

*/
void solve() {
    ll n, k;
    cin >> n >> k;
    vl a(n);
    rep(i, 0, n) cin >> a[i];
    ll min_sum = accumulate(all(a), 0LL);
    ll max_el = *max_element(all(a));
    ll max_set_size = n;
    while (max_set_size > 1) {
        ll max_of_decs = (min_sum + k) / max_set_size;
        if (max_of_decs * max_set_size >= min_sum && max_of_decs >= max_el) {
            cout << max_set_size << endl;
            return;
        }
        max_set_size--;
    }
    cout << 1 << endl;
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
