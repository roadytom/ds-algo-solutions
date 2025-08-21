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
/**

*/
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    v<int> d;
    for (char c: s) d.pb(c - '0');
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        v<int> digits(10, 0);
        int distinct_count = 0;
        int max_freq = 0;
        for (int j = i; j < min(n, i + 100); j++) {
            if (digits[d[j]] == 0) {
                distinct_count++;
            }
            digits[d[j]]++;
            max_freq = max(max_freq, digits[d[j]]);
            if (max_freq <= distinct_count) ans++;
        }
    }
    cout << ans << endl;
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
