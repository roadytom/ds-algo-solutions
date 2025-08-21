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
#define mp make_pair

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
/**
_____

______

_______

___

3 + 2 + 1

n * (n - 1) / 2

N = 2 * 10 ^ 3

y1 = k * x1 + b
y2 = k * x2 + b
y1 - y2 = k * (x1 - x2)

k = (y1 - y2) / (x1 - x2);
nC4 = n! /(n-4)! 2 * 3 * 4
(n - 3) (n - 2) (n - 1) n

24


*/
void solve() {
    int n;
    cin >> n;
    map<double, int> counter;
    vector<pii> points(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = mp(x, y);
    }
    int inf_counts = 0;
    auto count_parallelograms = [&points, &n]() {
        map<pair<double, double>, int> counter;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                auto &first = points[i], &second = points[j];
                double mid_x = 1.0 * (first.first + second.first) / 2;
                double mid_y = 1.0 * (first.second + second.second) / 2;
                counter[mp(mid_x, mid_y)]++;
            }
        }
        ll res = 0;
        for (auto &[_, count]: counter) {
            res += 1LL * count * (count - 1) / 2;
        }
        return res;
    };
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto &first = points[i], &second = points[j];
            int xdiff = first.first - second.first;
            int ydiff = first.second - second.second;
            debug(i, j, 1.0 * ydiff / xdiff);

            if (xdiff == 0) {
                inf_counts++;
            } else {
                counter[1.0 * ydiff / xdiff]++;
            }
        }
    }
    ll ans = 1LL * inf_counts * (inf_counts - 1) / 2;
    for (auto &[_, count]: counter) {
        ans += 1LL * count * (count - 1) / 2;
    }
    debug(inf_counts);
    debug(counter);
    cout << ans - count_parallelograms() << endl;
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
