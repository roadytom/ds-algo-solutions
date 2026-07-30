/**
 * 3518
 * https://leetcode.com/problems/
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

// Macros
#define len(x) static_cast<int>((x).size())

// Constants
constexpr long long MOD = 1e9 + 7;
constexpr long long INF = 1e18;
constexpr long long MAXN = 2e6 + 5; // for factorial precomputation etc.

class SatMultinomial {
public:
    using Count = long long;
    static constexpr Count kNoLimit = 9223372036854775807LL; // INT64_MAX

    explicit SatMultinomial(Count limit = kNoLimit) : limit_(limit) {
    }

    Count limit() const { return limit_; }
    void set_limit(Count l) { limit_ = l; }

    // True if the value hit the cap, i.e. the real answer is >= limit.
    bool saturated(Count v) const { return v >= limit_; }

    // ---- n! ---------------------------------------------------------------
    Count factorial(Count n) const {
        if (n < 0) return 0;
        Count res = 1;
        for (Count i = 2; i <= n; ++i) {
            res = mul_sat(res, i);
            if (res >= limit_) return limit_;
        }
        return res;
    }

    // ---- C(n, r) ----------------------------------------------------------
    // Invariant: after step i, res == C(n-r+i, i), so every division is exact.
    Count binom(Count n, Count r) const {
        if (n < 0 || r < 0 || r > n) return 0;
        if (r > n - r) r = n - r; // C(n,r) == C(n,n-r)
#ifdef __SIZEOF_INT128__
        __int128 res = 1;
        for (Count i = 1; i <= r; ++i) {
            res = res * (n - r + i) / i;
            if (res >= (__int128) limit_) return limit_;
        }
        return (Count) res;
#else
        Count res = 1;
        for (Count i = 1; i <= r; ++i) {
            if (res > kNoLimit / (n - r + i)) return limit_;
            res = res * (n - r + i) / i;
            if (res >= limit_) return limit_;
        }
        return res;
#endif
    }

    // ---- n! / (g1! g2! ... gm!),  n = sum of the groups -------------------
    template<class Range>
    Count multinomial(const Range &groups) const {
        Count n = 0;
        for (auto g: groups) n += (Count) g;
        return multinomial(n, groups);
    }

    Count multinomial(initializer_list<Count> groups) const {
        return multinomial<initializer_list<Count> >(groups);
    }

    // ---- n! / (g1! g2! ... gm!),  n given explicitly ----------------------
    // Groups summing to less than n leave a factor of (n - sum)!, because
    // n!/(g1!g2!) == C(n,g1)*C(n-g1,g2)*(n-g1-g2)!.  Groups summing to more
    // than n return 0.
    template<class Range>
    Count multinomial(Count n, const Range &groups) const {
        if (n < 0) return 0;
        Count rem = n, res = 1;
        for (auto g_: groups) {
            Count g = (Count) g_;
            if (g < 0 || g > rem) return 0; // impossible split
            if (g == 0) continue;
            res = mul_sat(res, binom(rem, g));
            if (res >= limit_) return limit_;
            rem -= g;
        }
        if (rem > 1) res = mul_sat(res, factorial(rem));
        return res >= limit_ ? limit_ : res;
    }

    Count multinomial(Count n, initializer_list<Count> groups) const {
        return multinomial<initializer_list<Count> >(n, groups);
    }

    // ---- frequency table (array<int,26>, vector<int>, ...) ----------------
    template<class Range>
    Count from_frequencies(const Range &freq) const {
        Count n = 0;
        for (auto f: freq) n += (Count) f;
        return multinomial(n, freq);
    }

private:
    // a > limit/b proves a*b > limit without forming the product, so this
    // cannot overflow at any limit, including INT64_MAX.
    Count mul_sat(Count a, Count b) const {
        if (a <= 0 || b <= 0) return 0;
        if (a > limit_ / b) return limit_;
        Count p = a * b;
        return p >= limit_ ? limit_ : p;
    }

    Count limit_;
};

SatMultinomial cap(1e6 + 1);

class Solution {
public:
    string smallestPalindrome(string s, int k) {
        int n = len(s);
        vector<int> freq(26);
        for (int i = 0; i < n / 2; i++) {
            freq[s[i] - 'a']++;
        }
        int size = n / 2;
        if (k > calculate_options(freq)) {
            return "";
        }
        string left;
        left.reserve(n);
        for (int i = 0; i < n / 2; i++) {
            for (int c = 0; c < 26; c++) {
                if (freq[c] == 0) continue;
                freq[c]--;
                size--;
                long long total_after = calculate_options(freq);
                if (total_after >= k) {
                    left.push_back('a' + c);
                    break;
                } else {
                    k -= total_after;
                    freq[c]++;
                    size++;
                }
            }
        }
        string right = left;
        reverse(right.begin(), right.end());
        if (n % 2) left.push_back(s[n / 2]);
        left.append(right);
        return left;
    }


    long long calculate_options(vector<int> &freq) {
        return cap.from_frequencies(freq);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution sol;
    debug(sol.smallestPalindrome("bacab", 1));

    return 0;
}
