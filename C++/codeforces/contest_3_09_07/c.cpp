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
    ull a, b;
    cin >> a >> b;
    if (a % 2 == 0 && b % 2 != 0) {
        cout << -1 << endl;
        return;
    }
    if (a % 2 == 1 && b % 2 == 0 && b % 4 != 0) {
        cout << -1 << endl;
        return;
    }
    if (a % 2 == 0 && b % 2 == 0) {
        cout << 2ULL + a * (b / 2) << endl;
        return;
    }
    if (a % 2 == 1 && b % 2 == 1) {
        cout << 1ULL + a * b << endl;
        return;
    }
    cout << 2ULL + a * (b / 2) << endl;
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
