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
string to_binary(int num) {
    if (num == 0) return "0";
    string binary;
    while (num > 0) {
        binary = (char) ('0' + (num & 1)) + binary; // prepend '0' or '1'
        num >>= 1; // shift right
    }
    return binary;
}

int binary_to_int(string &binary) {
    int result = 0;
    for (char c: binary) {
        result = (result << 1) + (c - '0');
    }
    return result;
}

void solve() {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << k << endl;
        return;
    }
    int index = 0;
    int x = k;
    while ((x >> 1) != 0) {
        index++;
        x >>=1;
    }
    int all_bits = (1 << index) - 1;
    cout << all_bits << " " << k - all_bits << " ";
    // debug(index);

    // debug(to_binary(31), to_binary(7));
    rep(i, 0, n - 2) cout << 0 << " ";
    cout << endl;
    // assert(__builtin_popcount(31 | 20) == __builtin_popcount(3 | 1| 1| 32 |2 |12));
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
