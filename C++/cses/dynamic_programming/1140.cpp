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
void maxi(ll &a, ll b) {
    a = max(a, b);
}

void solve() {
    int n;
    cin >> n;
    // end, <start, reward>
    v<pair<int, pair<int, ll> > > projects(n);
    rep(i, 0, n) cin >> projects[i].s.f >> projects[i].f >> projects[i].s.s;
    sort(all(projects));
    // coordinate compression
    v<int> coord;
    for (auto &[fst, snd]: projects) {
        coord.pb(fst);
        coord.pb(snd.f);
    }
    sort(all(coord));
    int id = 1;
    unordered_map<int, int> coord_comp;
    for (auto x: coord) {
        if (!coord_comp.count(x)) {
            coord_comp[x] = id;
            id++;
        }
    }
    auto get_el_idx = [&](int el) { return coord_comp[el]; };
    vector<vector<pair<int, int> > > project(id);
    for (int i = 0; i < n; i++) {
        project[get_el_idx(projects[i].f)].emplace_back(get_el_idx(projects[i].s.f), projects[i].s.s);
    }
    // WHY CORRECT?
    v<ll> dp(id, 0);
    for (int end = 1; end < id; end++) {
        dp[end] = dp[end - 1];
        for (auto [start, reward]: project[end]) {
            maxi(dp[end], dp[start - 1] + reward);
        }
    }
    debug(dp);
    // dp.assign(id, 0);
    // // WHY WRONG?
    // for (int i = 0; i < n;) {
    //     int j = i;
    //     while (j < n && projects[i].f == projects[j].f) j++;
    //     int end_idx = get_el_idx(projects[i].f);
    //     dp[end_idx] = dp[end_idx - 1];
    //     for (int k = i; k < j; k++) {
    //         auto &[start, reward] = projects[k].s;
    //         maxi(dp[end_idx], dp[get_el_idx(start) - 1] + reward);
    //     }
    //     i = j;
    // }
    // debug(dp);
    cout << dp[id - 1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
