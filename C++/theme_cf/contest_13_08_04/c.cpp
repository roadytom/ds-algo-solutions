#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
/**

*/
bool get_bit(ll num, ll pos) {
    return num & (1LL << pos);
}

void solve() {
    ll a, b, r;
    cin >> a >> b >> r;
    ll x = 0;
    if (a > b) swap(a, b);
    ll original_a = a, original_b = b;
    bool first_differ_found = false;
    for (ll pos = 59; pos >= 0; pos--) {
        int a_bit = get_bit(a, pos);
        int b_bit = get_bit(b, pos);
        if (a_bit != b_bit) {
            if (!first_differ_found) {
                first_differ_found = true;
            } else {
                if (!a_bit && b_bit && x + (1LL << pos) <= r) {
                    a = a ^ (1LL << pos);
                    b = b ^ (1LL << pos);
                    x += (1LL << pos);
                }
            }
        }
    }
    ll option1 = b - a;
    debug(option1);
    a = original_a;
    b = original_b;
    first_differ_found = false;
    bool possible = true;
    x = 0LL;
    for (ll pos = 60; pos >= 0; pos--) {
        ll mask = 1LL << pos;
        if (!first_differ_found) {
            if (((b & mask) != 0) && ((a & mask) == 0)) {
                first_differ_found = true;
                if (mask > r) {
                    possible = false;
                    break;
                }
                b = b ^ mask;
                a = a ^ mask;
                x += mask;
            }
        } else {
            if (((b & mask) == 0) && ((a & mask) != 0) && x + mask <= r) {
                a = a ^ mask;
                b = b ^ mask;
                x += mask;
            }
        }
    }
    if (possible) {
        cout << min(option1, a - b) << endl;
    } else {
        cout << option1 << endl;
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
