#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Function to handle fast input/output
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

int main() {
    setup_io();

    int N;
    std::cin >> N;

    // Use 1-based indexing for easier formula translation
    std::vector<int> a(N + 1), b(N + 1);
    for (int i = 1; i <= N; ++i) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= N; ++i) {
        std::cin >> b[i];
    }

    long long total_matches = 0;

    // ## Case 1: Position 'i' is OUTSIDE the reversal interval [l, r]
    // A match occurs if a[i] == b[i]. We count the number of intervals
    // that do not contain i.
    for (int i = 1; i <= N; ++i) {
        if (a[i] == b[i]) {
            long long i_ll = i;
            long long N_ll = N;
            // Count intervals [l, r] where r < i
            total_matches += (i_ll - 1) * i_ll / 2;
            // Count intervals [l, r] where l > i
            total_matches += (N_ll - i_ll) * (N_ll - i_ll + 1) / 2;
        }
    }

    // ## Case 2: Position 'i' is INSIDE the reversal interval [l, r]
    // Group positions by species for efficient calculation.
    std::vector<std::vector<int> > pa(N + 1), pb(N + 1);
    for (int i = 1; i <= N; ++i) {
        pa[a[i]].push_back(i);
    }
    for (int i = 1; i <= N; ++i) {
        pb[b[i]].push_back(i);
    }

    // Iterate through each species
    for (int s = 1; s <= N; ++s) {
        if (pa[s].empty() || pb[s].empty()) {
            continue;
        }

        std::vector<int> &A = pa[s]; // Positions 'j' where a[j] = s
        std::vector<int> &B = pb[s]; // Positions 'i' where b[i] = s

        // Sorting is required for the two-pointer optimization
        // The problem statement guarantees lists are already sorted by position, but it's safer to sort.
        // sort(A.begin(), A.end());
        // sort(B.begin(), B.end());

        int m = A.size();
        int k = B.size();

        // Precompute prefix and suffix sums for list A (positions 'j')
        std::vector<long long> prefA(m + 1, 0);
        for (int i = 0; i < m; ++i) {
            prefA[i + 1] = prefA[i] + A[i];
        }
        std::vector<long long> suffA(m + 1, 0);
        for (int i = m - 1; i >= 0; --i) {
            suffA[i] = suffA[i + 1] + A[i];
        }

        // Calculate sum of C(i, j) for this species
        // C(i, j) = min(i, j) + (N+1 - i - j) * [i+j > N+1]

        // Part A: Calculate Sum of min(i, j)
        long long sum_min_s = 0;
        int q_ptr_min = 0;
        for (int i: B) {
            while (q_ptr_min < m && A[q_ptr_min] < i) {
                q_ptr_min++;
            }
            // Sum of A[j] for j < i
            sum_min_s += prefA[q_ptr_min];
            // Sum of i for j >= i
            sum_min_s += (long long) i * (m - q_ptr_min);
        }
        total_matches += sum_min_s;

        // Part B: Calculate Sum of correction term for i+j > N+1
        long long sum_correction_s = 0;
        int q_ptr_corr = m - 1;
        for (int i: B) {
            while (q_ptr_corr >= 0 && (long long) i + A[q_ptr_corr] > N + 1) {
                q_ptr_corr--;
            }
            int num_j = m - (q_ptr_corr + 1);
            if (num_j > 0) {
                long long sum_j = suffA[q_ptr_corr + 1];
                sum_correction_s += (long long) (N + 1 - i) * num_j - sum_j;
            }
        }
        total_matches += sum_correction_s;
    }

    std::cout << total_matches << std::endl;

    return 0;
}
