#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
/**

*/
struct DSU {
    vector<int> parent;
    vector<int> sz;
    int sets;


    explicit DSU(int n) : parent(n), sz(n, 1), sets(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find_set(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find_set(parent[i]);
    }

    bool union_sets(int a, int b) {
        int root_a = find_set(a);
        int root_b = find_set(b);
        if (root_a != root_b) {
            if (sz[root_a] < sz[root_b]) {
                swap(root_a, root_b);
            }
            parent[root_b] = root_a;
            sz[root_a] += sz[root_b];
            sets--;
            return true;
        }
        return false;
    }

    bool same(int a, int b) {
        return find_set(a) == find_set(b);
    }

    int size(int a) {
        return sz[find_set(a)];
    }

    int count() const {
        return sets;
    }
};

void solve() {
    int n;
    cin >> n;
    int m1, m2;
    cin >> m1 >> m2;
    DSU dsu1(n);
    DSU dsu2(n);
    for (int i = 0; i < m1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        dsu1.union_sets(a, b);
    }
    for (int i = 0; i < m2; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        dsu2.union_sets(a, b);
    }
    vector<pair<int, int> > options;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!dsu1.same(i, j) && !dsu2.same(i, j)) {
                options.emplace_back(i, j);
                dsu1.union_sets(i, j);
                dsu2.union_sets(i, j);
            }
        }
    }
    cout << (int) options.size() << endl;
    for (auto &[fst, sec]: options) {
        cout << fst + 1 << " " << sec + 1 << endl;
    }
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
