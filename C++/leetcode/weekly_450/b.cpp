/**
 * b
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

class Solution {
public:
    int minSwaps(vector<int> &nums) {
        int n = len(nums);
        vector<pair<int, int> > items;
        for (auto num: nums) {
            int digit_sum = get_digit_sum(num);
            items.emplace_back(digit_sum, num);
        }
        vector<pair<int, int> > original = items;

        sort(items.begin(), items.end());
        map<pair<int, int>, int> pair_to_idx;
        for (int i = 0; i < n; i++) {
            pair_to_idx[original[i]] = i;
        }
        debug(items);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            auto &curr = items[i];
            int original_idx = pair_to_idx[curr];
            if (original_idx == i) continue;
            debug(original[i], index);
            ans++;
            swap(original[original_idx], original[i]);
            swap(pair_to_idx[curr], pair_to_idx[original[original_idx]]);
        }
        return ans;
    }

    int get_digit_sum(int num) {
        int ans = 0;
        while (num != 0) {
            ans += num % 10;
            num /= 10;
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution sol;
    vector<int> temp{978678783,989995084,465932830,37255967};
    debug(sol.minSwaps(temp));

    return 0;
}
