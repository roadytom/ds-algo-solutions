/**
 * 17
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
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> ans;
        map<char, vector<char> > telephone = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}
        };
        auto rec = [&](this auto &self, int idx, string &curr) -> void {
            if (idx >= n) {
                ans.emplace_back(curr);
                return;
            }
            for (char &c: telephone[digits[idx]]) {
                curr.push_back(c);
                self(idx + 1, curr);
                curr.pop_back();
            }
        };
        string temp;
        rec(0, temp);
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution sol;
    debug(sol.letterCombinations("23"));

    return 0;
}
