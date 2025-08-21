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
#define ppb pop_back
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
using vi = vector<int>;

class Solution {
public:
    long long power(long long base, long long exp) {
        long long res = 1;
        long long MOD = 1e9 + 7;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        long long MOD = 1e9 + 7;
        return power(n, MOD - 2);
    }

    int xorAfterQueries(vector<int> &nums, vector<vector<int> > &queries) {
        int n = nums.size();
        long long MOD = 1e9 + 7;

        // This vector will store the product of all multipliers for each index.
        vector<long long> final_multipliers(n, 1);

        // We use square root decomposition on the query step 'k'.
        // A block size of around 400 is a good heuristic for n up to 10^5.
        const int BLOCK_SIZE = 400;

        map<int, vector<tuple<int, int, int> > > small_k_queries;

        // Separate queries into large k (processed naively) and small k (processed in batches).
        for (const auto &q: queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k > BLOCK_SIZE) {
                // For large k, the number of updates is small.
                // We can apply these directly.
                int idx = l;
                while (idx <= r) {
                    final_multipliers[idx] = (final_multipliers[idx] * v) % MOD;
                    idx += k;
                }
            } else {
                // For small k, we group them to process them more efficiently.
                small_k_queries[k].emplace_back(l, r, v);
            }
        }

        // Process the grouped small k queries.
        for (auto const &[k, k_queries]: small_k_queries) {
            // For each k, we have k independent subproblems based on the remainder.
            for (int rem = 0; rem < k; ++rem) {
                // Calculate the length of the sub-array for this remainder.
                int sub_array_len = (n - 1 - rem) / k + 1;
                if (sub_array_len <= 0) {
                    continue;
                }

                // We use a difference array for efficient range multiplicative updates.
                vector<long long> diff(sub_array_len + 1, 1);

                for (const auto &query_tuple: k_queries) {
                    int l = get<0>(query_tuple);
                    int r = get<1>(query_tuple);
                    int v = get<2>(query_tuple);

                    // A query only affects indices where index % k == l % k.
                    // If the current remainder 'rem' doesn't match the query's remainder, skip it.
                    if (l % k != rem) {
                        continue;
                    }

                    // Map the original query range [l, r] to the sub-array indices.
                    int start_idx = l / k;
                    int end_idx = (r - rem) / k; // Last element in sub-array with original index <= r

                    // Apply the multiplier at the start of the range.
                    if (start_idx < diff.size()) {
                        diff[start_idx] = (diff[start_idx] * v) % MOD;
                    }

                    // Apply the inverse at the end of the range.
                    if (end_idx + 1 < diff.size()) {
                        long long inv_v = modInverse(v);
                        diff[end_idx + 1] = (diff[end_idx + 1] * inv_v) % MOD;
                    }
                }

                // Use prefix products on the difference array to find the final multiplier
                // for each element in the sub-array.
                long long current_multiplier = 1;
                for (int i = 0; i < sub_array_len; ++i) {
                    current_multiplier = (current_multiplier * diff[i]) % MOD;
                    if (current_multiplier != 1) {
                        int original_idx = rem + i * k;
                        final_multipliers[original_idx] = (final_multipliers[original_idx] * current_multiplier) % MOD;
                    }
                }
            }
        }


        // Apply the aggregated multipliers to the initial array values.
        for (int i = 0; i < n; ++i) {
            nums[i] = (nums[i] * final_multipliers[i]) % MOD;
        }

        // Calculate the final bitwise XOR sum of all elements.
        long long xor_sum = 0;
        for (long long x: nums) {
            xor_sum ^= x;
        }

        return static_cast<int>(xor_sum);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    v<int> nums{1, 1, 1};
    v<v<int> > queries{{0, 2, 1, 4}};
    debug(s.xorAfterQueries(nums, queries));
    return 0;
}

