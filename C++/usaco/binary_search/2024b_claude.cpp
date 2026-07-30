#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

/**
 * @brief Checks if 'm' total presses can guarantee at least 'k' cans.
 * * This function calculates the minimum guaranteed cans from 'm' presses
 * by considering the worst-case mapping of presses to slots.
 * The logic is optimized to O(log n) using prefix sums and binary search (upper_bound).
 * * @param m The total number of button presses to check.
 * @param n The number of slots.
 * @param k The required number of cans.
 * @param a The sorted vector of can counts in each slot.
 * @param prefix_sum Precomputed prefix sums of the sorted vector 'a'.
 * @return True if 'm' presses are sufficient, false otherwise.
 */
bool check(long long m, int n, long long k, const std::vector<long long>& a, const std::vector<long long>& prefix_sum) {
    if (m == 0) return k <= 0;

    long long c = m / n; // Base number of presses for each button
    long long r = m % n; // Number of buttons that get an extra press

    // Find the number of slots 'p' where the capacity is less than or equal to 'c'.
    // std::upper_bound finds the first element greater than 'c'.
    // The distance from the beginning gives us the count of elements <= 'c'.
    int p = std::distance(a.begin(), std::upper_bound(a.begin(), a.end(), c));

    // Calculate cans from pressing each button 'c' times.
    // For slots with a_i <= c, we get a_i cans. Sum is prefix_sum[p].
    // For slots with a_i > c, we get 'c' cans. There are (n-p) such slots.
    long long base_cans = 0;
    if (p > 0) {
        base_cans += prefix_sum[p];
    }
    base_cans += (long long)(n - p) * c;

    // Calculate extra cans from the 'r' additional presses.
    // Worst case: these presses go to the 'r' slots with the fewest cans.
    // An extra can is obtained only if the slot's capacity a_i > c.
    // The slots with capacity > c start at index 'p'.
    // We count how many of the first 'r' slots have an index >= p.
    long long extra_cans = std::max(0LL, r - p);

    return base_cans + extra_cans >= k;
}

void solve() {
    int n;
    long long k;
    std::cin >> n >> k;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // Sort capacities to analyze the worst-case scenario.
    std::sort(a.begin(), a.end());

    // Precompute prefix sums for O(log n) check function.
    std::vector<long long> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + a[i];
    }

    // Binary search for the minimum number of presses 'm'.
    long long low = 0, high = 4e14; // A sufficiently large upper bound
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, n, k, a, prefix_sum)) {
            ans = mid;
            high = mid - 1; // Try for fewer presses
        } else {
            low = mid + 1; // Need more presses
        }
    }

    std::cout << ans << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}