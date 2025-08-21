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
const ll inf = 1LL << 62;

void floydWarshall(vector<vector<ll> > &m) {
    int n = len(m);
    rep(i, 0, n) m[i][i] = min(m[i][i], 0LL);
    rep(k, 0, n)
        rep(i, 0, n)
            rep(j, 0, n)
                if (m[i][k] != inf && m[k][j] != inf) {
                    auto newDist = max(m[i][k] + m[k][j], -inf);
                    m[i][j] = min(m[i][j], newDist);
                }
    rep(k, 0, n)
        if (m[k][k] < 0)
            rep(i, 0, n)
                rep(j, 0, n)
                    if (m[i][k] != inf && m[k][j] != inf) m[i][j] = -inf;
}

void solve() {
    int n, m;
    cin >> n >> m;
    v<v<ll> > mat(n + 1, v<ll>(n + 1, inf));
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        ll dist;
        cin >> dist;
        mat[a][b] = min(mat[a][b], dist);
        mat[b][a] = min(mat[a][b], dist);
    }
    int k;
    cin >> k;
    ll air_dist;
    cin >> air_dist;
    rep(i, 0, k) {
        int city;
        cin >> city;
        mat[city][0] = air_dist;
        mat[0][city] = 0;
    }
    floydWarshall(mat);
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b;
            cin >> a >> b;
            ll new_dist;
            cin >> new_dist;
            if (new_dist >= mat[a][b]) continue;
            mat[a][b] = new_dist;
            mat[b][a] = new_dist;
            for (int middle_node: {a, b}) {
                for (int i = 0; i <= n; i++) {
                    for (int j = 0; j <= n; j++) {
                        if (mat[i][middle_node] != inf && mat[middle_node][j] != inf) {
                            mat[i][j] = min(mat[i][j], mat[i][middle_node] + mat[middle_node][j]);
                        }
                    }
                }
            }
        } else if (t == 2) {
            int x;
            cin >> x;
            mat[x][0] = air_dist;
            mat[0][x] = 0;
            for (int middle_node: {x, 0}) {
                for (int i = 0; i <= n; i++) {
                    for (int j = 0; j <= n; j++) {
                        if (mat[i][middle_node] != inf && mat[middle_node][j] != inf) {
                            mat[i][j] = min(mat[i][j], mat[i][middle_node] + mat[middle_node][j]);
                        }
                    }
                }
            }
        } else {
            ull total_cost = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    ll dist = mat[i][j] != inf ? mat[i][j] : 0LL;
                    total_cost += dist;
                }
            }
            cout << total_cost << endl;
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
