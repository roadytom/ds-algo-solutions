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
    int h, w;
    cin >> h >> w;
    v<string> info(h);
    rep(i, 0, h) {
        cin >> info[i];
    }

    auto get_idx = [&](int r, int c) {
        return r * w + c;
    };

    auto inside = [&](int r, int c) {
        return 0 <= r && r < h && 0 <= c && c < w;
    };


    pii src, dest;
    cin >> src.f >> src.s >> dest.f >> dest.s;
    src.f--, src.s--, dest.f--, dest.s--;
    v<pii> drs1{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    v<pii> drs2{{0, 2}, {2, 0}, {-2, 0}, {0, -2}};
    v<v<pii> > graph(h * w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int k = 0; k < len(drs1); k++) {
                int r = i + drs1[k].f;
                int c = j + drs1[k].s;
                int r2 = i + drs2[k].f;
                int c2 = j + drs2[k].s;
                if (inside(r, c)) {
                    if (info[r][c] == '.') {
                        graph[get_idx(i, j)].emplace_back(get_idx(r, c), 0);
                    } else {
                        graph[get_idx(i, j)].emplace_back(get_idx(r, c), 1);
                    }
                }

                if (inside(r, c) && inside(r2, c2)) {
                    if (info[r][c] == '#' || info[r2][c2] == '#') {
                        graph[get_idx(i, j)].emplace_back(get_idx(r2, c2), 1);
                    } else {
                        graph[get_idx(i, j)].emplace_back(get_idx(r2, c2), 0);
                    }
                }
            }
        }
    }
    // for (auto &[val, weight]: graph[6 * w + 3]) {
    //     debug(val / w, val % w, weight);
    // }
    priority_queue<pii, v<pii>, greater<> > pq;
    const ll inf = LLONG_MAX / 2;
    v<ll> distance(h * w, inf);
    int start = get_idx(src.f, src.s);
    int end = get_idx(dest.f, dest.s);
    // debug(end);
    distance[start] = 0;
    pq.emplace(0, start);
    // debug(graph);
    while (!pq.empty()) {
        auto [curr_dist, curr_node] = pq.top();
        pq.pop();
        if (curr_dist > distance[curr_node]) continue;
        debug(curr_dist, curr_node / w, curr_node % w);
        if (curr_node == end) {
            cout << curr_dist << endl;
            return;
        }
        for (auto &[neighbor, weight]: graph[curr_node]) {
            if (distance[neighbor] > curr_dist + weight) {
                distance[neighbor] = curr_dist + weight;
                pq.emplace(distance[neighbor], neighbor);
            }
        }
    }
    // cout << distance[end] << endl;
    assert(1 !=1);
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
