#include <bits/stdc++.h>
#include <atcoder/modint>
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
/**

*/
const int MAXN = 1e5;
int spf[MAXN + 1];
using mint = atcoder::modint1000000007;

mint fast_pow(mint b, ll e) {
    mint ans = 1;
    // debug(b, e);

    for (; e; b = b * b, e /= 2)
        if (e & 1) ans = ans * b;
    // debug(ans);
    return ans;
}

class Solution {
public:
    void precompute() {
        for (int i = 2; i <= MAXN; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= MAXN; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }

    int totalBeauty(v<int> &nums) {
        map<int, multiset<int> > primes;
        precompute();
        for (int num: nums) {
            map<int, int> counter;
            while (num != 1) {
                counter[spf[num]]++;
                num /= spf[num];
            }
            for (auto &[prime, count]: counter) {
                primes[prime].insert(count);
            }
        }
        mint gcd_one_count = fast_pow(2, len(nums)) - 1;
        for (int i = 2; i <= *max_element(all(nums)); i++) {
            map<int, int> counter;
            int num = i;
            while (num != 1) {
                counter[spf[num]]++;
                num /= spf[num];
            }
            int elements_count = INT_MAX;
            for (auto &[prime, count]: counter) {
                auto& counts = primes[prime];
                counts.lower_bound(count)
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    v<int> temp{1, 2, 3};
    debug(s.totalBeauty(temp));
    return 0;
}
