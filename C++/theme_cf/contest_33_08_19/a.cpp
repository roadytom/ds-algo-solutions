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
    ll c;
    cin >> c;
    v<ll> s(n);
    rep(i, 0, n) cin >> s[i];
    ll left = 0LL;
    ll right = 1e9 + 10LL;
    auto calculate = [&](ll w) {
        ll res = 0;
        for (auto val: s) {
            res += (val + 2 * w) * (val + 2 * w);
            if (res > c) {
                return res;
            }
        }
        return res;
    };
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll res = calculate(mid);
        if (res == c) {
            cout << mid << endl;
            return;
        } else if (res < c) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    assert(1 != 1);
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
