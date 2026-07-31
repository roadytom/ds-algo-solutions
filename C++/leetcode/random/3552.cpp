/**
 * 3552
 * https://leetcode.com/problems/
 */
#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

#define len(x) static_cast<int>((x).size())

// Constants
constexpr long long MOD = 1e9 + 7;
constexpr long long INF = 1e18;
constexpr long long MAXN = 2e6 + 5; // for factorial precomputation etc.

class Solution {
public:
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};


    int minMoves(vector<string> &matrix) {
        int r = len(matrix), c = len(matrix[0]);
        map<char, vector<pair<int, int> > > connected_nodes;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (isupper(matrix[i][j])) {
                    connected_nodes[matrix[i][j]].emplace_back(i, j);
                }
            }
        }
        // 0 - 1 BFS
        queue<pair<int, int> > q;
        vector<vector<bool> > visited(r, vector<bool>(c, false));

        int dist = 0;
        q.emplace(0, 0);
        auto can_be_next = [&](int i, int j) {
            return i < r && i >= 0 && j < c && j >= 0 && !visited[i][j] && matrix[i][j] != '#';
        };
        while (!q.empty()) {
            int size = len(q);
            for (int i = 0; i < size; i++) {
                auto curr = q.front();
                q.pop();
                if (visited[curr.first][curr.second]) continue;

                vector<pair<int, int> > connected{curr};
                if (isupper(matrix[curr.first][curr.second])) {
                    connected = connected_nodes[matrix[curr.first][curr.second]];
                }
                for (auto node: connected) {
                    visited[node.first][node.second] = true;
                    if (node.first == r - 1 && node.second == c - 1) {
                        return dist;
                    }
                    for (auto &dr: dirs) {
                        int next_i = node.first + dr[0];
                        int next_j = node.second + dr[1];
                        if (can_be_next(next_i, next_j)) {
                            q.emplace(next_i, next_j);
                        }
                    }
                }
            }

            dist++;
        }
        return -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution sol;
    vector<string> temp{".#...",".#.#.",".#.#.","...#."};
    debug(sol.minMoves(temp));

    return 0;
}
