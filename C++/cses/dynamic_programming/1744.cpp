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
void mini(ll &a, ll b) {
    a = min(a, b);
}

void solve() {
    int A, B;
    cin >> A >> B;
    const ll INF = LLONG_MAX / 2;
    v<v<ll> > min_moves(A + 1, v<ll>(B + 1, INF));
    rep(a, 1, A + 1) {
        rep(b, 1, B + 1) {
            if (a == b) min_moves[a][b] = 0;
            else {
                for (int i = 1; i < a; i++) {
                    mini(min_moves[a][b], min_moves[i][b] + min_moves[a - i][b] + 1);
                }
                for (int i = 1; i < b; i++) {
                    mini(min_moves[a][b], min_moves[a][i] + min_moves[a][b - i] + 1);
                }
            }
        }
    }
    debug(min_moves);
    cout << min_moves[A][B] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
