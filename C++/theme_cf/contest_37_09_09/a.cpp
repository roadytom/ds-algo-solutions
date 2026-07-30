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
    string s;
    cin >> s;
    if (len(s) == 1) {
        cout << (s[0] == '1') << endl;
        return;
    }
    ll max_ones = 0;
    s = s + s;
    for (int i = 0; i < len(s);) {
        debug(i);
        if (s[i] == '0') {
            i++;
            continue;
        }
        int j = i;
        while (j < len(s) && s[j] == '1') j++;
        max_ones = max(max_ones, 1LL * j - i);
        i = j;
    }
    if (max_ones >= len(s) / 2) {
        cout << 1LL * len(s) / 2 * len(s) / 2 << endl;
        return;
    }
    ll len = (max_ones + 1) / 2;
    cout << len * (max_ones - len + 1) << endl;
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
