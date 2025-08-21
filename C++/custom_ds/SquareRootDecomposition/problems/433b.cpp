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

ll query(const v<ll> &blocks, const v<ll> &arr, int l, int r, const int BLOCK) {
    int left_idx = l / BLOCK, right_idx = r / BLOCK;
    if (left_idx == right_idx) {
        ll ans = 0;
        for (int i = l; i <= r; i++) {
            ans += arr[i];
        }
        return ans;
    }
    ll ans = 0;
    for (int i = l; i < (left_idx + 1) * BLOCK; i++) {
        ans += arr[i];
    }
    for (int i = left_idx + 1; i < right_idx; i++) {
        ans += blocks[i];
    }
    for (int i = right_idx * BLOCK; i <= r; i++) {
        ans += arr[i];
    }
    return ans;
}

/**

*/
void solve() {
    int n;
    cin >> n;
    v<ll> vals(n);
    rep(i, 0, n) cin >> vals[i];
    auto sorted_vals = vals;
    sort(all(sorted_vals));

    const int BLOCK = (int) sqrt(n) + 1;
    v<ll> blocks1(BLOCK, 0);
    v<ll> blocks2(BLOCK, 0);
    for (int i = 0; i < n; i++) {
        blocks1[i / BLOCK] += vals[i];
        blocks2[i / BLOCK] += sorted_vals[i];
    }
    int m;
    cin >> m;
    while (m--) {
        int type;
        cin >> type;
        int l, r;
        cin >> l >> r;
        r--;
        l--;
        if (type == 1) {
            cout << query(blocks1, vals, l, r, BLOCK) << endl;
        } else {
            cout << query(blocks2, sorted_vals, l, r, BLOCK) << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
