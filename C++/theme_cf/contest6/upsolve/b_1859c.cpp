#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// This function calculates the best possible sum of products for a given `max_product` limit.
// It returns -1 if it's impossible to form a valid permutation under this limit.
ll calculate_score_for_max(int max_product, int n) {
    // 1. Group partners by their limit.
    // partners_by_limit[i] will store all numbers 'j' from {1..n}
    // such that the largest number they can be paired with is 'i'.
    // i.e., floor(max_product / j) == i.
    vector<vector<int> > partners_by_limit(n + 1);
    for (int j = n; j >= 1; j--) {
        int limit = max_product / j;
        if (limit > n) {
            limit = n; // A partner can't be paired with a number > n.
        }
        if (limit == 0) {
            return -1;
        }
        partners_by_limit[limit].push_back(j);
    }

    // 2. Perform the greedy pairing using a priority queue.
    // The priority queue will store all partners currently available.
    stack<int> available_partners;
    ll current_sum = 0;
    for (int i = 1; i <= n; i++) {
        available_partners.push(i);
        for (auto x: partners_by_limit[i]) {
            if (available_partners.empty()) {
                return -1;
            }
            current_sum += available_partners.top() * x;
            available_partners.pop();
        }
    }


    return current_sum;
}


void solve() {
    int n;
    cin >> n;

    ll max_final_score = 0;

    // 1. Identify all possible values for the maximum product.
    // We only need to check values that can be formed by i*j.
    // vector<bool> is_possible_product(n * n + 1, false);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int mx = i * j;

            // For this candidate 'mx', find the best permutation sum.
            ll total_sum = calculate_score_for_max(mx, n);

            // If a valid permutation was possible...
            if (total_sum != -1) {
                // ...calculate the final score and update the maximum.
                max_final_score = max(max_final_score, total_sum - mx);
            }
        }
    }

    cout << max_final_score << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // The problem seems to be designed around a single test case structure,
    // although the template might suggest multiple.
    // If multiple test cases were intended, a more optimized approach
    // might be needed than O(N^3 * logN) per case.
    // However, for a single case with N<=2000, this corrected logic is the way to go.
    int t = 1;
    cin >> t;
    // cin >> t; // Assuming one test case as per typical problem structure
    while (t--) {
        solve();
    }

    return 0;
}
