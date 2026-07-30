/**
 * a
 * https://codeforces.com/
 */
#include <bits/stdc++.h>
#include <atcoder/internal_type_traits.hpp>
using namespace std;
using namespace atcoder;

#define len(x) static_cast<int>((x).size())

// Constants
constexpr long long MOD = 1e9 + 7;
constexpr long long INF = 1e18;
constexpr long long MAXN = 2e6 + 5; // for factorial precomputation etc.

void solve() {
    int k;
    cin >> k;
    int two = 0;
    int three = 0;
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        if (x >= 2) two++;
        if (x >= 3) three++;
    }
    if (two >= 2 || three >= 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}