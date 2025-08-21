#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
using ll = long long;

const int MAXN = 2001; // Max n from problem statement is 2000

ll sum[MAXN];
ll sum_sq[MAXN];

// Precompute prefix sums for i and i^2 to speed up calculations.
void precompute() {
    sum[0] = 0;
    sum_sq[0] = 0;
    for (int i = 1; i < MAXN; ++i) {
        sum[i] = sum[i - 1] + i;
        sum_sq[i] = sum_sq[i - 1] + (ll)i * i;
    }
}

void solve() {
    int n;
    cin >> n;

    ll max_total_score = 0;

    // Iterate through all k from 0 to n-1 to find the optimal permutation structure.
    for (int k = 0; k < n; ++k) {
        // Calculate the sum of products S(k) for the permutation P(k)
        // P(k) = [1, ..., k, k+2, ..., n, k+1]

        // Sum part from i=1 to k is sum of i*i
        ll part1_sum = sum_sq[k];

        // Sum part from i=k+1 to n-1 is sum of i*(i+1)
        // which is (sum of i^2 from k+1 to n-1) + (sum of i from k+1 to n-1)
        ll part2_sum_sq = sum_sq[n - 1] - sum_sq[k];
        ll part2_sum = sum[n - 1] - sum[k];
        ll part2_sum_total = part2_sum_sq + part2_sum;

        // Sum part for i=n is n * (k+1)
        ll part3_sum = (ll)n * (k + 1);

        ll current_total_sum = part1_sum + part2_sum_total + part3_sum;

        // Determine the maximum product M(k)
        ll max_prod;
        if (k == n) { // Should be k == n-1 for identity permutation
             max_prod = (ll)n * n;
        } else {
             max_prod = (ll)n * (n-1);
             // A small edge case check
             if (k > 0) max_prod = max(max_prod, (ll)k*k);
        }
         // For n=2, k=0, p=[2,1]. M=2. n*(n-1)=2. ok.
        if (n>2 && k==n-1) max_prod = (ll)n*n;


        max_total_score = max(max_total_score, current_total_sum - max_prod);
    }

    // The loop structure above is a bit messy. A cleaner way:
    max_total_score = 0;
    for (int k=0; k<n; ++k) {
        ll current_S = sum_sq[n-1] + sum[n-1] - sum[k] + (ll)n*(k+1);
        ll current_M;
        if(k == n-1) { // Identity permutation
            current_M = (ll)n * n;
        } else {
            current_M = (ll)n * (n-1);
        }
        max_total_score = max(max_total_score, current_S - current_M);
    }


    cout << max_total_score << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}