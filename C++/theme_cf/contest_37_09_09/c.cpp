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
    v<v<int> > towers(n);
    v<int> all_blocks;
    rep(i, 0, n) {
        int k;
        cin >> k;
        rep(j, 0, k) {
            int block;
            cin >> block;
            all_blocks.pb(block);
            towers[i].pb(block);
        }
    }
    sort(all(all_blocks));
    map<int, int> el_to_idx;
    int id = 0;
    for (int block: all_blocks) {
        el_to_idx[block] = id;
        id++;
    }
    auto get_idx = [&](int el) { return el_to_idx[el]; };
    v<ll> unsorted_segments_count(n);
    for (int i = 0; i < n; i++) {
        auto &blocks = towers[i];
        ll cnt = 0;
        for (int j = 0; j < len(blocks);) {
            int k = j + 1;
            while (k < len(blocks) && get_idx(blocks[k - 1]) + 1 == get_idx(blocks[k])) k++;
            j = k;
            cnt++;
        }
        unsorted_segments_count[i] = cnt;
    }
    debug(unsorted_segments_count);
    ll res = 0;
    ll total_segments = 0;
    for (ll cnt: unsorted_segments_count) {
        res += cnt - 1;
        total_segments += cnt;
    }
    cout << res << " " << total_segments - 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
