#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

// Function to check if a target value 'm' is achievable
// Returns the permutation if achievable, otherwise an empty vector.
vector<int> check(int n, int m) {
    if (m > n && m != 0) {
        // A special case: if m > n, we can't even pick m itself.
        // But if m is a combination of numbers <= n, it might be possible.
        // A simple check can be done, but the logic inside handles it.
        // However, if the initial required_mask can't be satisfied by any number <= n, it might fail.
        // Example: n=6, m=7. No number is a supermask of 7.
        // Let's refine the logic for the first odd step from the back.
    }

    set<int> available_nums;
    for (int i = 1; i <= n; ++i) {
        available_nums.insert(i);
    }

    vector<int> p(n + 1);
    int required_mask = m;

    for (int i = n; i >= 2; --i) {
        if (i % 2 != 0) {
            // Odd step: k = k & p_i
            auto it = available_nums.lower_bound(required_mask);
            int best_p = -1;
            // Find the smallest number that is a supermask of required_mask
            while (it != available_nums.end()) {
                if ((*it & required_mask) == required_mask) {
                    best_p = *it;
                    break;
                }
                ++it;
            }

            if (best_p == -1) {
                return {}; // Not possible
            }
            p[i] = best_p;
            available_nums.erase(best_p);
        } else {
            // Even step: k = k | p_i
            int best_p = *available_nums.rbegin();
            p[i] = best_p;
            available_nums.erase(best_p);
            required_mask &= (~best_p);
        }
    }

    // Final check for p_2
    // k_2 = p_2, k_1 = 0. k_2 = k_1 | p_2 = p_2.
    // The requirement for k_2 is the final required_mask.
    if ((p[2] & required_mask) == required_mask) {
        p[1] = *available_nums.begin();
        vector<int> result_p;
        for (int i = 1; i <= n; ++i) {
            result_p.push_back(p[i]);
        }
        return result_p;
    }

    return {};
}

void solve() {
    int n;
    cin >> n;

    int max_k = 0;
    int max_bits = (n > 0) ? (int) floor(log2(n)) + 1 : 0;

    for (int b = max_bits; b >= 0; --b) {
        int next_k_candidate = max_k | (1 << b);
        if (next_k_candidate > 2 * n) continue; // Optimization: k can't be excessively large

        if (!check(n, next_k_candidate).empty()) {
            max_k = next_k_candidate;
        }
    }

    cout << max_k << endl;
    vector<int> p = check(n, max_k);
    for (int i = 0; i < n; ++i) {
        cout << p[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
