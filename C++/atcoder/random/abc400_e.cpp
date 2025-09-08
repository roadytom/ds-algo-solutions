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
ll MAXN = 1e12 + 5;
int prime_maxn = 5e5 + 5;
v<ll> fh_nums;

void precompute() {
    int prime_maxn = 1e6 + 5; // Fix range
    v<bool> is_prime(prime_maxn, true);
    v<int> primes;

    // Generate primes
    for (int i = 2; i < prime_maxn; i++) {
        if (is_prime[i]) {
            primes.pb(i);
            for (ll j = (ll) i * i; j < prime_maxn; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // Generate 400 numbers more efficiently
    for (int i = 0; i < primes.size(); i++) {
        for (int j = i + 1; j < primes.size(); j++) {
            ll p1 = primes[i], p2 = primes[j];
            ll base = p1 * p1 * p2 * p2; // p1^2 * p2^2
            if (base > MAXN) break;

            for (ll pow1 = base; pow1 <= MAXN; pow1 *= p1 * p1) {
                for (ll pow2 = pow1; pow2 <= MAXN; pow2 *= p2 * p2) {
                    fh_nums.pb(pow2);
                }
            }
        }
    }
    sort(all(fh_nums));
}

void solve() {
    precompute();
    int q;
    cin >> q;
    // debug(fh_nums);
    // debug(len(fh_nums));
    while (q--) {
        ll a;
        cin >> a;
        ll nums = *prev(upper_bound(all(fh_nums), a));
        cout << nums << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
