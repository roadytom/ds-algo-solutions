/**
* 3014
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
    /**
    max = 8
    xxx
    xx
    xx
    xx
    xx
    8 * 1 + 8 * 2
    23
    8 + 8 + 7
    2
    8 * (1 + 2)
    8 * (1 + n) * n / 2 + (total - div * 8) * (n + 1)
     */
    int minimumPushes(string word) {
        map<char, int> freq;
        for (char c : word){
            freq[c]++;
        }
        map<int, int> freq_to_char;
        for (const auto &[c, cnt] : freq) {
            freq_to_char[cnt]++;
        }
        int ans = 0;
        int level = 1;
        int count = 8;
        debug(freq_to_char);
        for (auto it = freq_to_char.rbegin(); it != freq_to_char.rend(); it++) {
            int fr = it->first;
            int cnt = it->second;
            int curr = 0;
            if (count >= cnt) {
                count -= cnt;
                curr += cnt * level;
            } else {
                curr += count * level;
                cnt -= count;
                count = 8;
                level++;
                int full_group = cnt / 8;
                int rem = cnt - full_group * 8;
                curr += 8 * (2 * level + full_group - 1) * full_group / 2 + rem * (full_group + level);
                count = 8 - rem;
                level += full_group;
            }
            debug(curr, fr, level, count);
            ans += curr * fr;
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution sol;
    debug(sol.minimumPushes("xyzxyzxyzxyz"));
    return 0;
}