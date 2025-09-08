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
    int n, m;
    cin >> n >> m;
    v<bool> xors(n + 2);
    string s;
    cin >> s;
    string t;
    cin >> t;
    rep(i, 0, m) {
        int l, r;
        cin >> l >> r;
        xors[l] = xors[l] ^ true;
        xors[r + 1] = xors[r + 1] ^ true;
    }
    bool prefix = false;
    for (int i = 1; i <= n; i++) {
        prefix = prefix ^ xors[i];
        if (prefix) {
            swap(s[i - 1], t[i - 1]);
        }
    }
    cout << s << endl;
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
