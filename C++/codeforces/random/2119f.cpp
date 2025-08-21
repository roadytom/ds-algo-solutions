#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

int solve() {
    int n, st;
    cin >> n >> st;

    vector<int> weights(n);
    for (int i = 0; i < n; ++i)
        cin >> weights[i];

    vector<vector<int> > adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Compute distances from root (vertex 1)
    vector<int> dist_from_root(n + 1, INT_MAX);
    dist_from_root[1] = 0;
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor: adj[node]) {
            if (dist_from_root[neighbor] == INT_MAX) {
                dist_from_root[neighbor] = dist_from_root[node] + 1;
                q.push(neighbor);
            }
        }
    }

    // Optimized BFS with minimal state tracking
    unordered_map<long long, int> visited; // key = vertex * 10000 + time
    queue<tuple<int, int, int> > bfs;
    bfs.push({st, 0, 1});
    int max_moves = 0;

    while (!bfs.empty()) {
        auto [vertex, time, life] = bfs.front();
        bfs.pop();

        int new_life = life + weights[vertex - 1];

        if (new_life <= 0 || dist_from_root[vertex] <= time)
            continue;

        max_moves = max(max_moves, time);

        long long key = 1LL * vertex * 10000 + time;
        if (visited.count(key) && visited[key] >= new_life)
            continue;
        visited[key] = new_life;

        if (time >= 2 * n)
            continue;

        for (int next_vertex: adj[vertex]) {
            int next_time = time + 1;
            if (dist_from_root[next_vertex] <= next_time)
                continue;
            bfs.push({next_vertex, next_time, new_life});
        }
    }

    return max_moves + 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cout << solve() << "\n";
    }
    return 0;
}