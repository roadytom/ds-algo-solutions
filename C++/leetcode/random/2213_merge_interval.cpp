/**
 * 2213_merge_interval
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
    vector<int> longestRepeating(string s, string qc, vector<int> &qi) {
        set<pair<int, int> > segments; // start, end inclusive
        multiset<int> lengths;
        int n = len(s);
        // build original segments and lengths;
        int left = 0, right = 0;
        while (right < n) {
            if (s[left] != s[right]) {
                segments.insert({left, right - 1});
                lengths.insert(right - left);
                left = right;
            }
            right++;
        }
        segments.insert({left, right - 1});
        lengths.insert(right - left);


        auto update = [&](int pos, char c) {
            auto it = segments.upper_bound({pos, INT_MAX});
            it--;
            int L = it->first, R = it->second;
            segments.erase(it);
            lengths.erase(lengths.find(R - L + 1));
            if (pos - 1 >= L) {
                segments.insert({L, pos - 1});
                lengths.insert(pos - L);
            }
            if (pos + 1 <= R) {
                segments.insert({pos + 1, R});
                lengths.insert(R - pos);
            }
            s[pos] = c;
        };
        auto merge = [&](int pos, char c) {
            int new_left = pos, new_right = pos;
            if (pos > 0 && s[pos - 1] == c) {
                auto it = segments.upper_bound({pos - 1, INT_MAX});
                it--;
                int L = it->first, R = it->second;
                new_left = L;
                segments.erase(it);
                lengths.erase(lengths.find(R - L + 1));
            }
            if (pos + 1 < n && s[pos + 1] == c) {
                auto it = segments.upper_bound({pos + 1, INT_MAX});
                it--;
                int L = it->first, R = it->second;
                new_right = R;
                segments.erase(it);
                lengths.erase(lengths.find(R - L + 1));
            }
            segments.insert({new_left, new_right});
            lengths.insert(new_right - new_left + 1);
        };

        vector<int> ans(len(qi));
        for (int q = 0; q < len(qi); q++) {
            int pos = qi[q];
            char c = qc[q];
            if (s[pos] != c) {
                update(pos, c);
                merge(pos, c);
            }
            debug(segments);
            debug(lengths);
            ans[q] = *lengths.rbegin();
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution sol;
    vector<int> temp{1, 3, 3};
    debug(sol.longestRepeating("babacc", "bcb", temp));

    return 0;
}
