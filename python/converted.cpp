#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

vector<vector<int>> graph;
vector<int> depth;
vector<vector<int>> up;
int max_log;

void preprocess(int n) {
    stack<pair<int, int>> stk;
    stk.push({0, -1});
    while (!stk.empty()) {
        auto [node, parent] = stk.top();
        stk.pop();
        for (int child : graph[node]) {
            if (child == parent) continue;
            depth[child] = depth[node] + 1;
            up[child][0] = node;
            for (int j = 1; j < max_log; ++j) {
                up[child][j] = up[up[child][j - 1]][j - 1];
            }
            stk.push({child, node});
        }
    }
}

int find_lca(int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);
    int k = depth[b] - depth[a];
    for (int i = 0; i < max_log; ++i) {
        if (k & (1 << i)) {
            b = up[b][i];
        }
    }
    if (a == b) return a;
    for (int i = max_log - 1; i >= 0; --i) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    max_log = log2(n) + 1;
    graph.assign(n, vector<int>());
    depth.assign(n, 0);
    up.assign(n, vector<int>(max_log, 0));

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;  // 0-indexed
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    preprocess(n);

    while (q--) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        int lca_node = find_lca(a, b);
        cout << depth[a] + depth[b] - 2 * depth[lca_node] << '\n';
    }

    return 0;
}