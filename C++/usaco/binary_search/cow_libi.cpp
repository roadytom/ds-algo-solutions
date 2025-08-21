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
    int g, n;
    cin >> g >> n;
    v<pair<ll, pll> > gg(g);
    rep(i, 0, g) {
        ll x, y, t;
        cin >> x >> y >> t;
        gg[i] = mp(t, mp(x, y));
    }
    v<pair<ll, pll> > alibi(n);
    rep(i, 0, n) {
        ll x, y, t;
        cin >> x >> y >> t;
        alibi[i] = mp(t, mp(x, y));
    }
    sort(all(gg));
    ll cnt = 0;
    auto manhattan_distance = [&](auto &first, auto &second) {
        return (first.f - second.f) * (first.f - second.f) + (first.s - second.s) * (first.s - second.s);
    };
    auto can_reach = [&](auto &first, auto &second) {
        auto &[t1, coord1] = first;
        auto &[t2, coord2] = second;
        ll dist = manhattan_distance(coord1, coord2);
        debug(dist);
        return dist <= (t2 - t1) * (t2 - t1);
    };
    debug(gg);
    rep(i, 0, n) {
        auto left = (int) (upper_bound(all(gg), alibi[i]) - gg.begin());
        bool innocent = false;
        for (int j = left - 1; j <= left; j++) {
            if (0 <= j && j < len(gg)) {
                innocent = innocent || !can_reach(gg[j], alibi[i]);
                if (can_reach(gg[j], alibi[i])) {
                    debug(i, gg[j], alibi[i]);
                }
            }
        }
        if (innocent) cnt++;
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("haybales.in", "r", stdin); // read from input.txt
    // freopen("haybales.out", "w", stdout); // write to output.txt
    solve();
    return 0;
}
