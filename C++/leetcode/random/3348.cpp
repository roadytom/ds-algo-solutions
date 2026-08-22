/**
 * 3348
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
    static string core(long long cur) {
        string s;
        while (cur > 1)
            for (int d = 9; d >= 2; --d)
                if (cur % d == 0) {
                    s += static_cast<char>('0' + d);
                    cur /= d;
                    break;
                }
        reverse(s.begin(), s.end());
        return s;
    }

public:
    string smallestNumber(string num, long long t) {
        auto possible = [](long long num) {
            for (int i = 9; i >= 2; i--) {
                while (num % i == 0) {
                    num /= i;
                }
            }
            return num == 1;
        };
        if (!possible(t)) return "-1";
        int n = len(num), p = -1;
        vector<long long> debts(n + 1); // debt that numbers from i..n - 1 must pay
        debts[0] = t;
        for (int i = 0; i < n; ++i) {
            int d = num[i] - '0';
            if (d == 0) {
                p = i;
                break;
            }
            debts[i + 1] = d ? debts[i] / gcd(debts[i], d) : debts[i];
        }
        if (p == -1 && debts[n] == 1) return num;
        if (p == -1) p = n - 1;
        for (int i = p; i >= 0; i--) {
            for (int x = num[i] - '0' + 1; x <= 9; x++) {
                string tail = core(debts[i] / gcd(debts[i], x));
                int k = n - 1 - i;
                if (len(tail) <= k) {
                    return num.substr(0, i) + (char) ('0' + x)
                           + string(k - tail.size(), '1') + tail;
                }
            }
        }
        string tail = core(t);
        int L = max(n + 1, len(tail));
        return string(L - tail.size(), '1') + tail;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution sol;
    string temp("78");
    debug(sol.smallestNumber(temp, 42));

    return 0;
}
