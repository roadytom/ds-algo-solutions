/**
 * 190
 * https://leetcode.com/problems/
 */
#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

#define len(x) static_cast<int>((x).size())

// Constants
constexpr long long MOD = 1e9 + 7;
constexpr long long INF = 1e18;
constexpr long long MAXN = 2e6 + 5; // for factorial precomputation etc.
/**
 * 00000010100101000001111010011100
 */
class Solution {
public:
    int reverseBits(int n) {
        int reverse = 0;
        for (int i = 0; i < 32; i++) {
            int curr_bit = n & (1 << i);
            if (curr_bit) {
                reverse |= (1 << (31 - i));
            }
        }
        return reverse;

    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution sol;
    debug(sol.reverseBits(43261596));

    return 0;
}