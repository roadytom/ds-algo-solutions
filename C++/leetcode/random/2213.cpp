/**
 * 2213
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
    vector<int> longestRepeating(string s, string chars, vector<int>& indices) {
        map<char, set<int>> char_to_idx;
        for (int i = 0; i < s.length(); i++) {
            char_to_idx[s[i]].insert(i);
        }
        vector<int> ans;
        for (int i = 0; i < chars.size(); i++) {
            char c = chars[i];
            int idx = indices[i];
            int start = -1;
            auto &idxs = char_to_idx[c];
            debug(idxs);
            auto it = idxs.upper_bound(idx);
            auto p = prev(it);
            if (*p == idx) {
                if (p != idxs.begin()) {
                    start = *(prev(p));
                } else {
                    start = -1;
                }
            } else {
                start = *p;
            }

            int end = it != idxs.end() ? *it : len(s);
            debug(start, end);

            ans.push_back(max(end - start - 1));
            idxs.insert(idx);
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution sol;
    vector<int> t{1, 3, 3};
    debug(sol.longestRepeating("babacc", "bcb", t));

    return 0;
}