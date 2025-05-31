#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

vector<vector<int>> dire = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<vector<int>> dire8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

class BinaryLiftingTree {
private:
    int nodes_count, max_log;
    vector<vector<int>> up;
    vector<vector<int>> up_min;
    vector<int> depth;
    vector<vector<pair<int, int>>> tree;
    bool _built = false;

    void dfs(int node, int parent) {
        for (auto &[child, weight] : tree[node]) {
            if (child == parent) continue;
            depth[child] = depth[node] + 1;
            up[child][0] = node;
            up_min[child][0] = weight;
            for (int log = 1; log < max_log; ++log) {
                if (up[child][log - 1] != -1) {
                    up[child][log] = up[up[child][log - 1]][log - 1];
                    up_min[child][log] = min(up_min[child][log - 1],
                                             up_min[up[child][log - 1]][log - 1]);
                }
            }
            dfs(child, node);
        }
    }

    void dfs_iterative(int root) {
        stack<pair<int, int>> stk;
        stk.push({root, -1});
        while (!stk.empty()) {
            auto [node, parent] = stk.top();
            stk.pop();
            for (auto &[child, weight] : tree[node]) {
                if (child == parent) continue;
                depth[child] = depth[node] + 1;
                up[child][0] = node;
                up_min[child][0] = weight;
                for (int log = 1; log < max_log; ++log) {
                    if (up[child][log - 1] != -1) {
                        up[child][log] = up[up[child][log - 1]][log - 1];
                        up_min[child][log] = min(up_min[child][log - 1],
                                                 up_min[up[child][log - 1]][log - 1]);
                    }
                }
                stk.push({child, node});
            }
        }
    }

public:
    BinaryLiftingTree(int n) : nodes_count(n) {
        max_log = log2(n) + 1;
        up.assign(n, vector<int>(max_log, -1));
        up_min.assign(n, vector<int>(max_log, INF));
        depth.assign(n, 0);
        tree.resize(n);
    }

    void add_edge(int a, int b, int weight) {
        tree[a].emplace_back(b, weight);
        tree[b].emplace_back(a, weight);
        _built = false;
    }

    void build(int root = 0, bool recursive = true) {
        if (recursive)
            dfs(root, -1);
        else
            dfs_iterative(root);
        _built = true;
    }

    int get_kth_ancestor(int node, int k) {
        if (!_built) throw runtime_error("Tree not built. Call build() before calling.");
        for (int i = 0; i < max_log; ++i) {
            if (k & (1 << i)) {
                node = up[node][i];
                if (node == -1) break;
            }
        }
        return node;
    }

    int get_kth_min_ancestor(int node, int k) {
        if (!_built) throw runtime_error("Tree not built. Call build() before calling.");
        int min_ancestor = INF;
        for (int i = 0; i < max_log; ++i) {
            if (k & (1 << i)) {
                min_ancestor = min(min_ancestor, up_min[node][i]);
                node = up[node][i];
                if (node == -1) break;
            }
        }
        return min_ancestor;
    }

    int get_lca(int u, int v) {
        if (!_built) throw runtime_error("Tree not built. Call build() before calling.");
        if (depth[u] > depth[v]) swap(u, v);
        int diff = depth[v] - depth[u];
        v = get_kth_ancestor(v, diff);
        if (u == v) return u;
        for (int log = max_log - 1; log >= 0; --log) {
            if (up[u][log] != -1 && up[u][log] != up[v][log]) {
                u = up[u][log];
                v = up[v][log];
            }
        }
        return up[u][0];
    }

    int get_distance(int u, int v) {
        int lca_node = get_lca(u, v);
        return depth[u] + depth[v] - 2 * depth[lca_node];
    }

    int get_min_in_path(int u, int v) {
        int lca_node = get_lca(u, v);
        return min(get_kth_min_ancestor(u, depth[u] - depth[lca_node]),
                   get_kth_min_ancestor(v, depth[v] - depth[lca_node]));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nodes_count, edges_count;
    cin >> nodes_count >> edges_count;

    BinaryLiftingTree tree(nodes_count);
    for (int i = 0; i < edges_count; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        tree.add_edge(a - 1, b - 1, w);
    }

    tree.build(0, false);

    int query_count;
    cin >> query_count;
    for (int i = 0; i < query_count; ++i) {
        int a, b;
        cin >> a >> b;
        cout << tree.get_min_in_path(a - 1, b - 1) << '\n';
    }

    return 0;
}