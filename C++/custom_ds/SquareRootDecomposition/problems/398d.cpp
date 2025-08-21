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

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    const int BLOCK = sqrt(m) + 1;
    int online;
    cin >> online;
    v<int> onlines;
    rep(i, 0, online) cin >> onlines[i];
    while (m--) {
        // TODO: edges a, b
    }
    while (q--) {
        char type;
        cin >> type;
        if (type == 'O') {
            int user;
            cin >> user;
            // TODO: make a user online
        } else if (type == 'F') {
            int user;
            cin >> user;
            // TODO: make a user offline
        } else if (type == 'A') {
            // TODO: add edge a, b
        } else if (type == 'D') {
            // TODO: delete edge a, b
        } else {
            int user;
            cin >> user;
            // TODO: count online friends of user
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
