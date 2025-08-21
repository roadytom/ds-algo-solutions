#include <iostream>
#include <vector>
#include <numeric>

// Set the modulus for all calculations
const int MOD = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    if (n == 0) {
        std::cout << 1 << std::endl;
        return;
    }

    // dp[i] stores H_i: the number of valid configurations for the first i people
    // where the i-th person is Honest.
    std::vector<long long> dp(n + 1);

    // Base Case: H_0
    // A conceptual state for an empty prefix. There's 1 way (the empty configuration),
    // considered to end "honestly" with 0 liars.
    dp[0] = 1;

    // Calculate H_1: Person 1 is Honest.
    // This requires 0 liars to their left, so their statement a[0] must be 0.
    dp[1] = (a[0] == 0) ? 1 : 0;

    // Calculate H_2: Person 2 is Honest.
    // Number of liars to their left must be a[1].
    // Path 1 (P1 was H): Liars = a[0]. Requires a[1] == a[0]. Ways = H_1 = dp[1].
    // Path 2 (P1 was L): Liars = 1. Requires a[1] == 1. Ways = L_1 = H_0 = dp[0].
    if (n >= 2) {
        long long ways_from_honest = (a[1] == a[0]) ? dp[1] : 0;
        long long ways_from_liar = (a[1] == 1) ? dp[0] : 0;
        dp[2] = (ways_from_honest + ways_from_liar) % MOD;
    }

    // Calculate H_i for i from 3 to n using the recurrence relation.
    for (int i = 3; i <= n; ++i) {
        // Path 1 (P(i-1) was H): Liars = a[i-2]. Requires a[i-1] == a[i-2]. Ways = H_{i-1} = dp[i-1].
        long long ways_from_honest = (a[i - 1] == a[i - 2]) ? dp[i - 1] : 0;

        // Path 2 (P(i-1) was L, so P(i-2) was H): Liars = a[i-3] + 1.
        // Requires a[i-1] == a[i-3] + 1. Ways = L_{i-1} = H_{i-2} = dp[i-2].
        long long ways_from_liar = (a[i - 1] == a[i - 3] + 1) ? dp[i - 2] : 0;

        dp[i] = (ways_from_honest + ways_from_liar) % MOD;
    }

    // Total configurations = (Ways ending in Honest) + (Ways ending in Liar)
    // Total = H_n + L_n = dp[n] + H_{n-1} = dp[n] + dp[n-1].
    long long total_ways = (dp[n] + dp[n - 1]) % MOD;
    std::cout << total_ways << std::endl;
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