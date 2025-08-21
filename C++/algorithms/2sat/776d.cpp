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
struct TwoSatSolver {
    int n_vars;
    int n_vertices;
    vector<vector<int>> adj, adj_t;
    vector<bool> used;
    vector<int> order, comp;
    vector<bool> assignment;

    TwoSatSolver(int _n_vars) : n_vars(_n_vars), n_vertices(2 * n_vars), adj(n_vertices), adj_t(n_vertices), used(n_vertices), order(), comp(n_vertices, -1), assignment(n_vars) {
        order.reserve(n_vertices);
    }
    void dfs1(int v) {
        used[v] = true;
        for (int u : adj[v]) {
            if (!used[u])
                dfs1(u);
        }
        order.push_back(v);
    }

    void dfs2(int v, int cl) {
        comp[v] = cl;
        for (int u : adj_t[v]) {
            if (comp[u] == -1)
                dfs2(u, cl);
        }
    }

    bool solve_2SAT() {
        order.clear();
        used.assign(n_vertices, false);
        for (int i = 0; i < n_vertices; ++i) {
            if (!used[i])
                dfs1(i);
        }

        comp.assign(n_vertices, -1);
        for (int i = 0, j = 0; i < n_vertices; ++i) {
            int v = order[n_vertices - i - 1];
            if (comp[v] == -1)
                dfs2(v, j++);
        }

        assignment.assign(n_vars, false);
        for (int i = 0; i < n_vertices; i += 2) {
            if (comp[i] == comp[i + 1])
                return false;
            assignment[i / 2] = comp[i] > comp[i + 1];
        }
        return true;
    }

    void add_disjunction(int a, bool na, int b, bool nb) {
        // na and nb signify whether a and b are to be negated
        a = 2 * a ^ na;
        b = 2 * b ^ nb;
        int neg_a = a ^ 1;
        int neg_b = b ^ 1;
        adj[neg_a].push_back(b);
        adj[neg_b].push_back(a);
        adj_t[b].push_back(neg_a);
        adj_t[a].push_back(neg_b);
    }

    // static void example_usage() {
    //     TwoSatSolver solver(3); // a, b, c
    //     solver.add_disjunction(0, false, 1, true);  //     a  v  not b
    //     solver.add_disjunction(0, true, 1, true);   // not a  v  not b
    //     solver.add_disjunction(1, false, 2, false); //     b  v      c
    //     solver.add_disjunction(0, false, 0, false); //     a  v      a
    //     assert(solver.solve_2SAT() == true);
    //     auto expected = vector<bool>(True, False, True);
    //     assert(solver.assignment == expected);
    // }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<bool> open(n);
    rep(i, 0, n) {
        int x;
        cin >> x;
        open[i] = x == 1;
    }
    TwoSatSolver solver(m);
    vector<vector<int> > door_sws(n);
    rep(i, 0, m) {
        int x;
        cin >> x;
        while (x--) {
            int door;
            cin >> door;
            door--;
            door_sws[door].push_back(i);
        }
    }
    debug(door_sws);
    rep(door, 0, n) {
        bool op = open[door];
        auto &sws = door_sws[door];
        assert((int) sws.size() == 2);
        solver.add_disjunction(sws[0], !op, sws[1], !op);
        cout << sws[0] << " " << !op << " " << sws[1] << " " << !op << endl;
    }
    if (solver.solve_2SAT()) {
        cout << "Yes" << endl;
        for (int i = 0; i < solver.n_vars; i++) {
            cout << "x" << i << " = " << (solver.assignment[i] ? "true" : "false") << endl;

        }
        // for (int i = 0; i < solver.num_variables; ++i) {
        // }
    } else {
        cout << "No" << endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
