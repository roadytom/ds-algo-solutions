#include <bits/stdc++.h>
#include <atcoder/segtree>

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
const int INF = INT_MAX / 2;

using S = int;

// op: The function to combine two data values (S). We need the minimum.
S op(S a, S b) { return max(a, b); }
// e: The identity element for the op function.
S e() { return 0; }
/**

*/

void solve_with_patience_sort_algorithm() {
    int n;
    cin >> n;
    v<int> arr(n);
    rep(i, 0, n) cin >> arr[i];
    v<int> dp(n, INF);
    for (int i = 0; i < n; i++) {
        // for (int j = 0; j <= i; j++) {
        //     if ((j - 1 < 0 || dp[j - 1] < arr[i]) && arr[i] < dp[j]) {
        //         dp[j] = arr[i];
        //         break;
        //     }
        // }
        auto idx = upper_bound(all(dp), arr[i]) - dp.begin();
        if ((idx - 1 < 0 || dp[idx - 1] < arr[i]) && arr[i] < dp[idx]) {
            dp[idx] = arr[i];
        }
        // debug(arr[i], dp);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] < INF) {
            ans = i + 1;
        }
    }
    cout << ans << endl;
    debug(dp);
}

void solve_with_segtree() {
    int n;
    cin >> n;
    v<int> arr(n);
    rep(i, 0, n) cin >> arr[i];
    set<int> sorted_unique;
    rep(i, 0, n) sorted_unique.insert(arr[i]);
    unordered_map<int, int> el_to_idx;
    int id = 0;
    for (auto el: sorted_unique) {
        el_to_idx[el] = id;
        id++;
    }
    debug(id);
    debug(el_to_idx);
    atcoder::segtree<S, op, e> seg(id);

    v<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
        int idx = el_to_idx[arr[i]];
        dp[i] = seg.prod(0, idx) + 1;
        debug(idx, dp[i]);

        seg.set(idx, dp[i]);
    }
    cout << seg.prod(0, id) << endl;
    debug(dp);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve_with_segtree();
    return 0;
}
