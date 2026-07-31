#include <bits/stdc++.h>

using namespace std;

// ==========================================================================
// ============  COPY FROM HERE  ============================================
// ==========================================================================
//
//  SatMultinomial -- computes  n! / (g1! * g2! * ... * gm!)  without overflow,
//  by saturating: any result >= limit is returned as exactly `limit`, which
//  means "at least this much".
//
//  It never builds a factorial.  The value is factored into binomials
//      n!/(g1!...gm!) == C(n,g1) * C(n-g1,g2) * C(n-g1-g2,g3) * ...
//  so every partial product is an integer near the final answer, and each
//  multiply is checked against the limit before it is performed.
//
//  Use when you only need to COMPARE the count against something (a k, a
//  threshold).  If you need the true value mod a prime, use factorials mod p
//  with modular inverses instead -- that is a different tool.
//
//      SatMultinomial mn(1000000);      // cap at 1e6; default cap is INT64_MAX
//      mn.multinomial({2, 2, 1});       // 30      = 5!/(2!2!1!)
//      mn.multinomial(10, {3, 2});      // 302400  = 10!/(3!2!), leftover 5 -> 5!
//      mn.from_frequencies(freq);       // for array<int,26> style tables
//      mn.binom(50, 25);                // 126410606437752
//      mn.factorial(20);                // 2432902008176640000
//      mn.saturated(v);                 // did v hit the cap?
//
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

// ==========================================================================
// ============  COPY TO HERE  ==============================================
// ==========================================================================


// ---- everything below is just a demo; delete it -------------------------
int main() {
    SatMultinomial mn; // uncapped (saturates at INT64_MAX)
    printf("5!/(2!2!1!)     = %lld   (30)\n", mn.multinomial({2, 2, 1}));
    printf("10!/(3!3!4!)    = %lld   (4200)\n", mn.multinomial({3, 3, 4}));
    printf("20!/(5!5!5!5!)  = %lld   (11732745024)\n", mn.multinomial({5, 5, 5, 5}));
    printf("10!/(3!2!)      = %lld   (302400)\n", mn.multinomial(10, {3, 2}));
    printf("C(50,25)        = %lld   (126410606437752)\n", mn.binom(50, 25));
    printf("20!             = %lld   (2432902008176640000)\n", mn.factorial(20));
    printf("21!             = %lld   <- saturated, would overflow\n", mn.factorial(21));

    SatMultinomial cap(1000001); // e.g. LeetCode 3518, k <= 1e6
    array<int, 26> freq{};
    freq[0] = 50000;
    freq[1] = 50000;
    long long v = cap.from_frequencies(freq);
    printf("100000!/(50000!50000!) = %lld  saturated=%d\n", v, (int) cap.saturated(v));
    return 0;
}
