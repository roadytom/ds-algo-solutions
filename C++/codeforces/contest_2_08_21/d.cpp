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

ll x_coins[18];

void solve() {
    ll n, k;
    cin >> n >> k;
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
    map<ll, ll> deals;
    ll min_deal_count = 0;
    while (n > 0) {
        ll x = find(n);
        ll tx = fast_pow(3LL, x);
        n -= tx;
        deals[x]++;
        min_deal_count++;

        coins += x_coins[x];
    }
    if (min_deal_count > k || n != 0) {
        cout << -1 << endl;
        return;
    }
    k -= min_deal_count;
    ll available_deals = 0;
    for (int i = 17; i >= 1; i--) {
        if (deals.count(i)) {
            available_deals += deals[i];
        }
        if (k < 2) {
            break;
        }
        ll number_to_transform = min(available_deals, k / 2);
        if (number_to_transform > 0) {
            coins -= number_to_transform * x_coins[i];
            coins += 3 * number_to_transform * x_coins[i - 1];
            k -= 2 * number_to_transform;
        }
        available_deals = 3 * number_to_transform;
    }
    cout << coins << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    ll val = 1;
    x_coins[0] = 3;
    for (int i = 1; i < 18; i++) {
        x_coins[i] = val * 3 * 3 + i * val;
        val *= 3;
    }
    debug(x_coins);
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
