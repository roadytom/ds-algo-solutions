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
const double INF = 1e9 + (2e10 + 5) * 1e9;

void solve() {
    int n;
    cin >> n;
    v<double> x(n), ve(n);
    rep(i, 0, n) cin >> x[i] >> ve[i];
    auto check = [&](double t) {
        double left = 1.0 * x[0] - t * ve[0];
        double right = 1.0 * x[0] + t * ve[0];
        debug(left, right);
        for (int i = 1; i < n; i++) {
            left = max(left, 1.0 * x[i] - t * ve[i]);
            right = min(right, 1.0 * x[i] + t * ve[i]);
        }
        // debug(left, right);
        return left <= right;
    };
    double left = 0.0, right = 2e10 + 5;
    for (int i = 0; i < 1000; i++) {
        double mid = left + (right - left) / 2;
        debug(mid);
        if (check(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    cout << fixed << setprecision(20) << left << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
