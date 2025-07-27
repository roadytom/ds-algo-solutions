#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>

// A helper function for modular arithmetic that correctly handles negative numbers.
long long safe_mod(long long x, long long m) {
    return ((x % m) + m) % m;
}

// Main logic to solve a single test case.
void solve() {
    int n;
    long long k;
    std::cin >> n >> k;
    std::vector<long long> p(n);
    for (int i = 0; i < n; ++i) std::cin >> p[i];
    std::vector<long long> d(n);
    for (int i = 0; i < n; ++i) std::cin >> d[i];
    int q;
    std::cin >> q;

    for (int i = 0; i < q; ++i) {
        long long start_pos;
        std::cin >> start_pos;

        // Find the first traffic light at or after the starting position using binary search.
        auto it = std::lower_bound(p.begin(), p.end(), start_pos);
        if (it == p.end()) {
            // No traffic lights ahead, so we will definitely leave the strip.
            std::cout << "YES\n";
            continue;
        }

        int current_idx = std::distance(p.begin(), it);

        // At t=0, we are at start_pos, moving right.
        // The time to reach the first light p[current_idx] is (p[current_idx] - start_pos).
        long long time_at_first_light = p[current_idx] - start_pos;

        int dir; // Direction: 1 for right, -1 for left.
        long long invariant; // This will hold the 'R' or 'L' invariant value.

        // Check if we turn at the very first light encountered.
        // A light is red at time `t` if `t % k == d`.
        if (safe_mod(time_at_first_light, k) == d[current_idx]) {
            // The light is red. We turn left.
            dir = -1;
            // The invariant for rightward movement is R = (t - pos) mod k.
            // Initially, at t=0, pos=start_pos, R = -start_pos mod k.
            long long R = safe_mod(-start_pos, k);
            // When turning from right to left at position `p_j`, the new invariant is L = (R + 2*p_j) mod k.
            invariant = safe_mod(R + 2 * safe_mod(p[current_idx], k), k);
        } else {
            // The light is green. We continue moving right.
            dir = 1;
            // The invariant R remains unchanged.
            invariant = safe_mod(-start_pos, k);
        }

        // Use a map to detect cycles. A state is defined by the current traffic light index and the invariant value.
        std::map<std::pair<int, long long>, bool> visited;

        bool will_escape = false;

        // We simulate the movement from one turning point to the next.
        // A loop must be detected within a reasonable number of steps, related to 2*n.
        for(int step = 0; step < 2 * n + 5; ++step) {

            if (visited.count({current_idx, invariant})) {
                // We have returned to a state (light index, invariant) that we've seen before.
                // This means we are in a cycle and will never leave the strip.
                will_escape = false; // Set to false explicitly, though it's the default
                break;
            }
            visited[{current_idx, invariant}] = true;

            if (dir == 1) { // We are moving to the right.
                // Find the next traffic light where we will turn around by linear scan.
                int next_turn_idx = -1;
                for (int j = current_idx + 1; j < n; ++j) {
                    // Turn condition for rightward movement with invariant R: R == (d_j - p_j) mod k
                    long long turn_condition_R = safe_mod(d[j] - safe_mod(p[j], k), k);
                    if (invariant == turn_condition_R) {
                        next_turn_idx = j;
                        break;
                    }
                }

                if (next_turn_idx == -1) {
                    // No more turning points to the right, so we escape.
                    will_escape = true;
                    break;
                }

                // We will turn at next_turn_idx. Update state.
                current_idx = next_turn_idx;
                dir = -1; // Change direction to left.
                // Update invariant from R to L: L = (R + 2*p_i) mod k
                invariant = safe_mod(invariant + 2 * safe_mod(p[current_idx], k), k);

            } else { // We are moving to the left.
                // Find the next traffic light where we will turn around by linear scan.
                int next_turn_idx = -1;
                for (int j = current_idx - 1; j >= 0; --j) {
                    // Turn condition for leftward movement with invariant L: L == (d_j + p_j) mod k
                    long long turn_condition_L = safe_mod(d[j] + safe_mod(p[j], k), k);
                    if (invariant == turn_condition_L) {
                        next_turn_idx = j;
                        break;
                    }
                }

                if (next_turn_idx == -1) {
                    // No more turning points to the left, so we escape.
                    will_escape = true;
                    break;
                }

                // We will turn at next_turn_idx. Update state.
                current_idx = next_turn_idx;
                dir = 1; // Change direction to right.
                // Update invariant from L to R: R = (L - 2*p_i) mod k
                invariant = safe_mod(invariant - 2 * safe_mod(p[current_idx], k), k);
            }
        }

        if (will_escape) {
            std::cout << "YES\n";
        } else {
            // If we didn't escape after the loop, we must be trapped.
            std::cout << "NO\n";
        }
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}