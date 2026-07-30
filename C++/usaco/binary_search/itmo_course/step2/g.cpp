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
    int k;
    cin >> k;
    int n;
    cin >> n;
    v<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    ll left = 1LL, right = LLONG_MAX / 2;
    auto check = [&](ll t) {
        ll layer = 0;
        int idx = 0;
        for (int i = 0; i < k; i++) {
            while (idx < n && layer < t) {
                layer = layer + min(a[idx], t);
                idx++;
            }
            if (layer < t) return false;
            layer -= t;
        }
        return true;
    };
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (check(mid)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << right << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
