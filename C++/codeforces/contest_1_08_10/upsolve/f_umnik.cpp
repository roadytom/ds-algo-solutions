#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

// Use long long for sums to avoid potential overflow.
using ll = long long;

// A struct to hold the calculated values for each prefix.
// This is clearer than using std::pair.
struct PrefixInfo {
    ll diff; // The value of (zeros - ones) for this prefix.
    ll ones; // The count of '1's in this prefix.
    ll zeros; // The count of '0's in this prefix.

    // Overload the '<' operator to allow sorting based on the 'diff' value.
    bool operator<(const PrefixInfo &other) const {
        return diff < other.diff;
    }

    // string str() const { return to_string(diff) + " " + to_string(ones) + " " + to_string(zeros); }
};

// SOLUTION FOR: Unsupported Type
// CPP_DUMP_DEFINE_EXPORT_OBJECT(PrefixInfo, diff, ones, zeros);


void solve() {
    int n;
    std::cin >> n;
    std::string s_a, s_b;
    std::cin >> s_a >> s_b;

    std::vector<PrefixInfo> a_infos(n), b_infos(n);

    // --- Step 1: Pre-computation and Transformation ---
    // Calculate the {zeros - ones, ones, zeros} tuple for each prefix of string 'a'.
    int zero_count = 0, one_count = 0;
    for (int i = 0; i < n; ++i) {
        if (s_a[i] == '0') zero_count++;
        else one_count++;
        a_infos[i] = {(ll) zero_count - one_count, (ll) one_count, (ll) zero_count};
    }

    // Do the same for string 'b'.
    zero_count = 0;
    one_count = 0;
    for (int i = 0; i < n; ++i) {
        if (s_b[i] == '0') zero_count++;
        else one_count++;
        b_infos[i] = {(ll) zero_count - one_count, (ll) one_count, (ll) zero_count};
    }

    // --- Step 2: Sorting ---
    // Sort both info arrays based on the 'diff' value (zeros - ones).
    // This is the key step that enables the two-pointer optimization.
    std::sort(a_infos.begin(), a_infos.end());
    std::sort(b_infos.begin(), b_infos.end());

    // --- Step 3: Create Prefix Sums on Sorted 'b' array ---
    // These will be used to calculate costs for segments of 'b' in O(1).
    std::vector<ll> pref_b_zeros(n + 1, 0);
    std::vector<ll> pref_b_ones(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pref_b_zeros[i + 1] = pref_b_zeros[i] + b_infos[i].zeros;
        pref_b_ones[i + 1] = pref_b_ones[i] + b_infos[i].ones;
    }

    ll total_answer = 0;
    // The second pointer 'p' starts at the end of the 'b' array.
    int p = n;
    debug(a_infos);
    debug(b_infos);

    // --- Step 4: Two-Pointer Sweep ---
    // Iterate through each prefix choice for string 'a'.
    for (int i = 0; i < n; ++i) {
        // Move pointer 'p' to the left until the condition for choosing "all 0s" is met.
        // The condition is a_infos[i].diff + b_infos[p-1].diff >= 0.
        // We loop while the opposite is true: a_infos[i].diff + b_infos[p-1].diff < 0
        while (p > 0 && a_infos[i].diff + b_infos[p - 1].diff > 0) {
            p--;
        }

        // Now, for the current a_infos[i], the b_infos array is split at index 'p'.

        // Group 1: b_infos[0...p-1]. For these 'p' elements, we make everything 0.
        // Cost = ones_a + ones_b.
        // Sum of costs = p * a_infos[i].ones + (sum of b_infos[j].ones for j=0..p-1)
        if (p > 0) {
            total_answer += (ll) p * a_infos[i].zeros + pref_b_zeros[p];
        }

        // Group 2: b_infos[p...n-1]. For these 'n-p' elements, we make everything 1.
        // Cost = zeros_a + zeros_b.
        // Sum of costs = (n-p) * a_infos[i].zeros + (sum of b_infos[j].zeros for j=p..n-1)
        if (n - p > 0) {
            total_answer += (ll) (n - p) * a_infos[i].ones + (pref_b_ones[n] - pref_b_ones[p]);
        }
    }

    std::cout << total_answer << std::endl;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
