#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited, deque<int> &order) {
    visited[node] = true;
    for (int adj : graph[node]) {
        if (!visited[adj])
            dfs(adj, graph, visited, order);
    }
    order.push_front(node);
}

void dfs2(int node, vector<vector<int>> &rev_graph, vector<bool> &visited, vector<int> &scc) {
    visited[node] = true;
    scc.push_back(node);
    for (int adj : rev_graph[node]) {
        if (!visited[adj])
            dfs2(adj, rev_graph, visited, scc);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> costs(n);
    for (int i = 0; i < n; ++i) {
        cin >> costs[i];
    }

    int m;
    cin >> m;
    vector<vector<int>> graph(n + 1), rev_graph(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        rev_graph[b].push_back(a);
    }

    // Step 1: Topological sort
    deque<int> topo_order;
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i, graph, visited, topo_order);
        }
    }

    // Step 2: Find SCCs on reversed graph
    visited.assign(n + 1, false);
    vector<vector<int>> sccs;
    for (int node : topo_order) {
        if (!visited[node]) {
            vector<int> scc;
            dfs2(node, rev_graph, visited, scc);
            sccs.push_back(scc);
        }
    }

    // Step 3: For each SCC, compute min cost and count
    long long total_min_sum = 0;
    long long ways = 1;

    for (const auto &scc : sccs) {
        int min_cost = INF;
        for (int node : scc) {
            min_cost = min(min_cost, costs[node - 1]); // node is 1-indexed
        }

        int count = 0;
        for (int node : scc) {
            if (costs[node - 1] == min_cost)
                ++count;
        }

        total_min_sum += min_cost;
        ways = (ways * count) % MOD;
    }

    cout << total_min_sum << " " << ways << "\n";

    return 0;
}