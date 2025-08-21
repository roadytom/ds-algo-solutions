#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
#define len(x) static_cast<int>((x).size())
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define v vector

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
/**

*/
const ll INF = 2e18;

class Solution {
public:
    ll maxSumTrionic(const vector<int> &nums) {
        int n = nums.size();
        // Use a very small number to represent negative infinity.
        // Dividing by 2 prevents overflow when adding two neg_inf values.

        // --- Part 1: Calculate max sum of an INCREASING subarray (len >= 2) ending at each index ---
        // This is a prerequisite for finding the inc-dec part.
        vector<ll> maxSumIncreasingEndingAt(n, -INF);
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                // An increasing subarray ending at `i` can either be just `[i-1, i]`
                // or `nums[i]` appended to the max-sum increasing subarray ending at `i-1`.
                ll sum_len_2 = (ll) nums[i] + nums[i - 1];
                ll extend_sum = -INF;
                if (maxSumIncreasingEndingAt[i - 1] != -INF) {
                    extend_sum = nums[i] + maxSumIncreasingEndingAt[i - 1];
                }
                maxSumIncreasingEndingAt[i] = max(sum_len_2, extend_sum);
            }
        }

        // --- Part 2: Calculate max sum of an INC-DEC subarray ending at each index ---
        // Both the increasing and decreasing parts must have a length of at least 2.
        vector<ll> maxSumIncDecEndingAt(n, -INF);
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                // Option 1: Start a new decreasing segment from a peak at i-1.
                // The increasing part must be valid (not NEG_INFINITY).
                ll newDecSegmentSum = -INF;
                if (maxSumIncreasingEndingAt[i - 1] != -INF) {
                    newDecSegmentSum = maxSumIncreasingEndingAt[i - 1] + nums[i];
                }

                // Option 2: Extend an existing inc-dec segment from i-1.
                ll extendIncDecSum = -INF;
                if (maxSumIncDecEndingAt[i - 1] != -INF) {
                    extendIncDecSum = maxSumIncDecEndingAt[i - 1] + nums[i];
                }

                maxSumIncDecEndingAt[i] = max(newDecSegmentSum, extendIncDecSum);
            }
        }

        // --- Part 3: Calculate max sum of an INCREASING subarray (len >= 2) starting at each index ---
        // We iterate from right to left.
        vector<ll> maxSumIncreasingStartingAt(n, -INF);
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                // An increasing subarray starting at `i` can either be just `[i, i+1]`
                // or `nums[i]` prepended to the max-sum increasing subarray starting at `i+1`.
                ll sum_len_2 = (ll) nums[i] + nums[i + 1];
                ll extend_sum = -INF;
                if (maxSumIncreasingStartingAt[i + 1] != -INF) {
                    extend_sum = nums[i] + maxSumIncreasingStartingAt[i + 1];
                }
                maxSumIncreasingStartingAt[i] = max(sum_len_2, extend_sum);
            }
        }

        // --- Part 4: Combine at the valley `q` to find the maximum trionic sum ---
        ll maxTrionicSum = -INF;
        // A trionic subarray `l...r` needs `l < p < q < r`.
        // This means `q` can range from index 2 to n-2.
        for (int q = 2; q < n - 1; ++q) {
            // Check if we have a valid left part (inc-dec) and a valid right part (inc).
            if (maxSumIncDecEndingAt[q] != -INF && maxSumIncreasingStartingAt[q] != -INF) {
                // The value at `nums[q]` is the valley, which is part of both the left
                // and right sums. We subtract it once to avoid double-counting.
                ll currentTotalSum = maxSumIncDecEndingAt[q] + maxSumIncreasingStartingAt[q] - nums[q];
                maxTrionicSum = max(maxTrionicSum, currentTotalSum);
            }
        }

        return maxTrionicSum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    v<int> temp{0, -2, -1, -3, 0, 2, -1};
    debug(s.maxSumTrionic(temp));
    return 0;
}
