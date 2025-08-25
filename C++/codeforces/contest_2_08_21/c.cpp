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
ll fast_pow(ll b, ll e) {
    ll ans = 1;
    // debug(b, e);

    for (; e; b = b * b, e /= 2)
        if (e & 1) ans = ans * b;
    // debug(ans);
    return ans;
}

void solve() {
    ll n;
    cin >> n;
    const double log3 = log(3.0);
    ll coins = 0;
    auto find = [&](ll num) {
        ll pow = 0;
        ll val = 1;
        while (val * 3 <= num) {
            pow++;
            val *= 3;
        }
        return pow;
    };
    while (n > 0) {
        ll x = find(n);
        ll tx = fast_pow(3LL, x);
        n -= tx;
        coins += tx * 3 + x * tx / 3;
        debug(x);
    }
    cout << coins << endl;
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
