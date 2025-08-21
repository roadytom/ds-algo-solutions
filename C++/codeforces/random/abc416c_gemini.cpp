#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

// It's good practice to use long long for variables that can hold large numbers,
// like the rank 'x' or counts of combinations, to prevent overflow errors.
using ll = long long;

// We can remove the inefficient 'comb' function entirely.
// All the logic is now handled efficiently inside 'solve'.

void solve() {
    int n;
    ll k, x;
    std::cin >> n >> k >> x;

    std::vector<std::string> options(n);
    for (int i = 0; i < n; i++) {
        std::cin >> options[i];
    }

    // First, sort the options to ensure they are in lexicographical order.
    // This is essential for the mathematical logic to work.
    std::sort(options.begin(), options.end());

    std::string result;
    // Adjust x to be 0-indexed (i.e., from 1...n^k to 0...n^k-1).
    // This greatly simplifies the division and modulo arithmetic.
    x--;

    // This loop builds the result string from left to right.
    // 'pos' represents the number of characters we still need to choose.
    for (ll pos = k; pos > 0; --pos) {
        // Calculate the number of combinations possible with the remaining (pos - 1) characters.
        // This value is n^(pos - 1) and represents the "size" of each block of combinations
        // that start with the same prefix.
        ll blockSize = 1;
        for (int i = 0; i < pos - 1; ++i) {
            // We can assume inputs are such that this won't overflow,
            // because the total number of combinations is at least x.
            blockSize *= n;
        }

        // Determine the index of the correct option for the current position.
        // This is done by seeing which block our target 'x' falls into.
        ll optionIndex = x / blockSize;

        // Append the chosen option to our result string.
        result += options[optionIndex];

        // Update x to be the remainder. This effectively "zooms in" on the next
        // block of combinations for the subsequent character.
        x %= blockSize;
    }

    std::cout << result << std::endl;
}

int main() {
    // These lines are standard practice in competitive programming
    // to speed up C++ input/output operations.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}
