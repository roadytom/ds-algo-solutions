#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
#define len(x) static_cast<int>((x).size())
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define v vector
#define len(x) static_cast<int>((x).size())

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
const int MAXN = 4 * (1e3);
vector<int> primes;

void precompute() {
    v<bool> is_prime(MAXN, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAXN; i++) {
        if (is_prime[i]) {
            for (int j = 2 * i; j < MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i < MAXN; i++) {
        if (is_prime[i]) primes.pb(i);
    }
}

void solve() {
    int n;
    cin >> n;
    v<int> arr(n);
    rep(i, 0, n) cin >> arr[i];
    map<int, int> factors;
    debug(primes);
    for (int num: arr) {
        for (int prime: primes) {
            if (prime * prime > num) break;
            while (num % prime == 0) {
                factors[prime]++;
                num /= prime;
            }
        }
        if (num > 1) factors[num]++;
    }
    debug(factors);
    int res = 0;
    int left_overs = 0;
    for (auto &[_, count]: factors) {
        res += count / 2;
        left_overs += count % 2;
    }
    res += left_overs / 3;
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    precompute();
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
