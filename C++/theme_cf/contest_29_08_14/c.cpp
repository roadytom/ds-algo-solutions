#include <iostream>
#include <vector>
#include <string>
#include <queue>

void solve() {
    // Use fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::cin >> n >> k;

    std::vector<std::string> walls(2);
    std::cin >> walls[0] >> walls[1];

    // BFS queue stores {wall, area} pairs.
    // wall: 0 for left, 1 for right. area: 1-indexed.
    std::queue<std::pair<int, int> > q;

    // visited[wall][area] prevents redundant computations.
    // Size is n+2 to be safe with indexing, especially for area + k.
    std::vector<std::vector<bool> > visited(2, std::vector<bool>(n + 2, false));

    // 1. Initialize with the starting state.
    q.push({0, 1}); // Start at left wall (0), area 1.
    visited[0][1] = true;

    int time = 0;
    bool possible = false;

    // 2. Start the BFS loop.
    while (!q.empty()) {
        int level_size = q.size(); // Number of states at the current time.

        for (int i = 0; i < level_size; ++i) {
            std::pair<int, int> curr = q.front();
            q.pop();
            int wall = curr.first;
            int area = curr.second;

            // Optimization: If water level `time` has caught up to `area`, this path is dead.
            if (time >= area) {
                continue;
            }

            // After the next move, time will be `t+1`. New area must be > t+1.

            // Move 1: Climb Up
            int next_area_up = area + 1;
            if (next_area_up > n) {
                possible = true;
                break;
            }
            if (!visited[wall][next_area_up] && walls[wall][next_area_up - 1] == '-') {
                visited[wall][next_area_up] = true;
                q.push({wall, next_area_up});
            }

            // Move 2: Climb Down
            int next_area_down = area - 1;
            // The destination must be above the new water level (time + 1).
            // This also ensures the area is valid (>= 1), as time is non-negative.
            if (next_area_down > time + 1) {
                if (!visited[wall][next_area_down] && walls[wall][next_area_down - 1] == '-') {
                    visited[wall][next_area_down] = true;
                    q.push({wall, next_area_down});
                }
            }

            // Move 3: Jump to the other wall
            int next_wall_jump = 1 - wall;
            int next_area_jump = area + k;
            if (next_area_jump > n) {
                possible = true;
                break;
            }
            // The destination must also be above the new water level.
            if (next_area_jump > time + 1) {
                if (!visited[next_wall_jump][next_area_jump] && walls[next_wall_jump][next_area_jump - 1] == '-') {
                    visited[next_wall_jump][next_area_jump] = true;
                    q.push({next_wall_jump, next_area_jump});
                }
            }
        }

        if (possible) {
            break;
        }

        // 3. A full second (one level of moves) has passed.
        time++;
    }

    // 4. Print the final result.
    if (possible) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    solve();
    return 0;
}
