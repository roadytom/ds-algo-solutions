#include <iostream>
#include <vector>
#include <numeric>

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n;
    std::vector<long long> p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }

    // Start with the sum of all the '+1' terms from the formula
    long long total_sum = (long long)n * (n + 1) / 2;

    // Add the contributions from each descent
    // For a descent at p[i] > p[i+1] (0-based index i),
    // it is contained in (i+1) * (n - (i+1)) subarrays.
    for (int i = 0; i < n - 1; ++i) {
        if (p[i] > p[i + 1]) {
            total_sum += (long long)(i + 1) * (n - (i + 1));
        }
    }

    std::cout << total_sum << std::endl;
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