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
    string s;
    cin >> s;
    v<int> left_zero(n), right_one(n);
    left_zero[0] = (s[0] == '0') ? 0 : -1;
    right_one[n - 1] = (s[n - 1] == '1') ? n - 1 : n;
    for (int i = 1; i < n; i++) {
        if (s[i] == '0') {
            left_zero[i] = i;
        } else {
            left_zero[i] = left_zero[i - 1];
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == '1') {
            right_one[i] = i;
        } else {
            right_one[i] = right_one[i + 1];
        }
    }
    debug(left_zero);
    debug(right_one);
    set<pii> counter;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int ll = right_one[l];
        int rr = left_zero[r];
        if (ll > rr) {
            counter.insert({-1, -1});
        } else {
            counter.insert({ll, rr});
        }
    }
    debug(counter);
    cout << len(counter) << endl;
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
