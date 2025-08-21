#include <bits/stdc++.h>
#include <atcoder/lazysegtree.hpp>
#include <atcoder/modint.hpp>
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
/**

*/
using mint = atcoder::modint;

void solve() {
    int n, m;
    cin >> n >> m;
    mint::set_mod(m);
    vector<int> a(n);
    rep(i, 0, n) {
        int x;
        cin >> x;
        a[i] = x;
    }
    string s;
    cin >> s;
    int left = 0, right = n - 1;
    for (char c: s) {
        if (c == 'L') {
            left++;
        } else {
            right--;
        }
    }
    mint prod = 1;
    for (int i = left; i <= right; i++) {
        prod *= a[i];
    }
    reverse(all(s));
    vector<mint> res;
    for (char c: s) {
        if (c == 'L') {
            left--;
            prod *= a[left];
            res.pb(prod);
        } else {
            right++;
            prod *= a[right];
            res.pb(prod);
        }
    }
    for (int i = len(res) - 1; i >= 0; i--) {
        cout << res[i] << " ";
    }
    cout << endl;
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
