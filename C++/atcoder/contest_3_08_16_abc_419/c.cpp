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
    v<ll> rows(n), cols(n);
    rep(i, 0, n) {
        cin >> rows[i] >> cols[i];
    }
    auto temp = rows;
    auto temp1 = cols;
    sort(all(temp));
    sort(all(temp1));
    ll fst = (temp[0] + temp[n - 1]) / 2;
    ll snd = (temp1[0] + temp1[n - 1]) / 2;
    debug(fst, snd);
    debug(rows, cols);
    ll ans = 0;
    rep(i, 0, n) {
        auto r = rows[i], c = cols[i];
        debug(abs(fst - r), abs(snd - c));
        ans = max(ans, max(abs(fst - r), abs(snd - c)));
    }
    cout << ans << endl;
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
