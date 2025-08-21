#include <iostream>
#include <vector>
#include <numeric>

const int MAXN = 1000001;
long long dp[MAXN];

// Precomputes the DP table
void precompute() {
    dp[0] = 0;
    long long current_n = 1;
    long long jump_size = 1;

    while (current_n < MAXN) {
        for (int count = 0; count < row && current_n < MAXN; ++count) {
            // Note: We need to cast i*i to long long to prevent overflow
            long long i_sq = current_n * current_n;
            dp[current_n] = i_sq + dp[current_n - jump_size];
            current_n++;
        }
        jump_size++;
    }
}

void solve() {
    int n;
    std::cin >> n;
    std::cout << dp[n] << "\n";
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    precompute();

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
