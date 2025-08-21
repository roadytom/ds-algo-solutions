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

*/
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> cities(n), towers(m);
    rep(i, 0, n) cin >> cities[i];
    rep(i, 0, m) cin >> towers[i];
    sort(all(towers));
    sort(all(cities));
    int p = 0;
    int r = INT_MIN;
    for (int i = 0; i < n; i++) {
        while (p + 1 < m && abs(cities[i] - towers[p]) >= abs(cities[i] - towers[p + 1])) p++;
        debug(cities[i], towers[p]);
        r = max(r, abs(cities[i] - towers[p]));
    }
    cout << r << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
