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
ll distance(pair<ll, ll> &a, pair<ll, ll> &b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve() {
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    a--, b--;
    vector<pair<ll, ll> > cities;
    rep(i, 0, n) {
        ll r, c;
        cin >> r >> c;
        cities.emplace_back(r, c);
    }
    ll min_distance = distance(cities[a], cities[b]);
    vector<ll> distances_a(k);
    for (int i = 0; i < k; i++) {
        distances_a[i] = distance(cities[a], cities[i]);
    }
    vector<ll> distances_b(k);
    for (int i = 0; i < k; i++) {
        distances_b[i] = distance(cities[b], cities[i]);
    }
    if (k != 0) {
        min_distance = min(min_distance, *min_element(all(distances_a)) + *min_element(all(distances_b)));
    }
    cout << min_distance << endl;
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
