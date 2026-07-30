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
    int n;
    cin >> n;
    v<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    ll res = 0LL;
    auto choose2 = [](ll x) { return x * (x + 1) / 2; };
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            res += choose2(i) + choose2(n - i - 1) + min(i, n - i - 1) + 1;
        }
    }
    auto count = [&](int i, int j) {
        // return max(0, min(i, j) - max(1, i + j + n) + 1);
        int left = min(i, j);
        int right = max(n - i - 1, n - j - 1);
        return max(0, min(left, right)) + 1;
        // return max(0, max(1, i + j + n) - min(i, j) + 1);
    };
    rep(_, 0, 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (a[i] == b[j]) {
                    res += count(i, j);
                    // res += min(i, n - j - 1) + 1;
                }
            }
        }
        // reverse(all(a));
        // reverse(all(b));
    }

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
