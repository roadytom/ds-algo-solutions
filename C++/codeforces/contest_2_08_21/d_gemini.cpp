#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>

// Use long long for all relevant variables to avoid overflow
using namespace std;
using ll = long long;

const int MAX_POW = 40; // Safely larger than needed for n <= 10^9
ll p3[MAX_POW];
ll costs[MAX_POW];

// Pre-calculate powers of 3 and the cost for each deal type
void precompute() {
    p3[0] = 1;
    for (int i = 1; i < MAX_POW; ++i) {
        if (p3[i-1] > 2e18 / 3) { // Prevent overflow during precomputation
            p3[i] = 2e18;
        } else {
            p3[i] = p3[i - 1] * 3;
        }
    }

    // Cost for deal type 0: 3^(0+1) + 0 * 3^(0-1) = 3
    costs[0] = 3;
    for (int i = 1; i < MAX_POW; ++i) {
        // Cost for deal type i: 3^(i+1) + i * 3^(i-1)
        costs[i] = 3 * p3[i] + (ll)i * p3[i - 1];
    }
}

void solve() {
    ll n, k;
    cin >> n >> k;

    // Step 1: Get the standard base-3 representation of n.
    // This gives the combination with the minimum number of deals.
    vector<ll> counts(MAX_POW, 0);
    ll min_deals = 0;
    ll initial_cost = 0;
    ll temp_n = n;
    int max_i = 0;

    for (int i = 0; i < MAX_POW && temp_n > 0; ++i) {
        int digit = temp_n % 3;
        if (digit > 0) {
            counts[i] = digit;
            min_deals += digit;
            initial_cost += (ll)digit * costs[i];
            max_i = i;
        }
        temp_n /= 3;
    }

    // Step 2: Feasibility check.
    if (k < min_deals) {
        cout << -1 << endl;
        return;
    }

    // Step 3: Greedy cost reduction.
    // Each transformation (1 deal of type i -> 3 deals of type i-1) increases the deal count by 2.
    ll num_transforms = (k - min_deals) / 2;
    ll final_cost = initial_cost;

    // Greedily break down the largest available deal types first to maximize savings.
    for (int i = max_i; i >= 1; --i) {
        if (num_transforms == 0) {
            break;
        }

        // Determine how many deals of the current type 'i' we can/should transform.
        ll transforms_to_do = min(counts[i], num_transforms);

        if (transforms_to_do > 0) {
            // The saving for breaking down a type 'i' deal is 3^(i-1).
            ll cost_reduction = transforms_to_do * p3[i - 1];
            final_cost -= cost_reduction;

            num_transforms -= transforms_to_do;

            // The transformed deals become deals of a smaller type, available for the next iteration.
            counts[i - 1] += 3 * transforms_to_do;
        }
    }

    cout << final_cost << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}