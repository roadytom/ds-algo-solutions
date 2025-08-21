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
/**

*/
ll distance(ll a, ll b) {
    return abs(a - b);
}

void solve() {
    ll l, r, x, a, b;
    cin >> l >> r >> x >> a >> b;
    if (b < a) {
        ll original_l = l;
        l = b - distance(a, r);
        r = a + distance(b, original_l);
        swap(a, b);
    }
    debug(l, r, a, b);
    if (a == b) {
        cout << 0 << endl;
    } else if (distance(a, b) >= x) {
        cout << 1 << endl;
    } else if (distance(a, l) >= x) {
        cout << 2 << endl;
    } else if (distance(b, r) >= x) {
        cout << 2 << endl;
    } else if ((distance(l, a) + distance(b, a) >= x) && distance(a, r) >= x) {
        cout << 3 << endl;
    } else {
        cout << -1 << endl;
    }
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
