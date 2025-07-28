#include <bits/stdc++.h>
using namespace std;

// Macros
#define ll unsigned long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii std::pair<int, int>
#define vii std::vector<pii>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)


// Constants
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;
constexpr ll MAXN = 2e6 + 5; // for factorial precomputation etc.


// Fast Exponentiation
ll mod_exp(ll base, ll exp, ll mod = MOD) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

// Modular Inverse (assuming MOD is prime)
ll mod_inv(ll x) {
    return mod_exp(x, MOD - 2);
}

// Modular Arithmetic Helpers
ll mod_add(ll a, ll b) {
    return (a + b) % MOD;
}

ll mod_sub(ll a, ll b) {
    return (a - b + MOD) % MOD;
}

ll mod_mul(ll a, ll b) {
    return a * b % MOD;
}

// Combinatorics
vector<ll> fact;
vector<ll> inv_fact;

void precompute_factorials(int max_n) {
    if (!fact.empty() && fact.size() > max_n) return;
    fact.assign(max_n + 1, 1);
    inv_fact.assign(max_n + 1, 1);

    fact[0] = inv_fact[0] = 1;
    for (ll i = 1; i <= max_n; i++) {
        fact[i] = mod_mul(fact[i - 1], i);
    }
    inv_fact[max_n] = mod_inv(fact[max_n]);
    for (ll i = max_n - 1; i >= 1; i--) {
        inv_fact[i] = mod_mul(inv_fact[i + 1], i + 1);
    }
}

// nCr
ll comb(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return mod_mul(fact[n], mod_mul(inv_fact[r], inv_fact[n - r]));
}

// nPr
ll perm(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return mod_mul(fact[n], inv_fact[n - r]);
}

template<typename T>
void read_vector(vector<T> &v, ll n) {
    v.resize(n);
    for (ll i = 0; i < n; ++i) cin >> v[i];
}

/** PRINT VECTOR **/
template<typename T>
struct is_vector : false_type {
};

template<typename T, typename Alloc>
struct is_vector<vector<T, Alloc> > : true_type {
};

template<typename T>
enable_if_t<!is_vector<T>::value>
print_nested(const T &val, ostream &os) {
    os << val;
}

template<typename T>
enable_if_t<is_vector<T>::value>
print_nested(const T &vec, ostream &os) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        print_nested(vec[i], os);
        if (i + 1 != vec.size()) os << ", ";
    }
    os << "]";
}

template<typename T>
void print_vector(const T &vec) {
    print_nested(vec, cout);
    cout << '\n';
}

/** END OF PRINT VECTOR **/

/** CREATE MULTI-D VECTOR **/
template<typename T>
vector<T> make_vector(size_t size, T val) {
    return vector<T>(size, val);
}

template<typename T, typename... Args>
auto make_vector(size_t size, Args... args) {
    return vector<decltype(make_vector<T>(args...))>(size, make_vector<T>(args...));
}

/** END OF CREATION MULTI-D VECTOR **/

/**

*/
void solve() {
    ll n, c;
    cin >> n >> c;
    vector<ll> costs(n);
    rep(i, 0, n) {
        cin >> costs[i];
    }
    sort(all(costs));
    ll q = n;
    ll mult = 1;
    ll ans = 0;
    while (q--) {
        auto it = lower_bound(all(costs), c, [&](const ll el, const ll target) {
            return el * mult <= target;
        });

        if (it == costs.begin()) {
            ans += costs.size();
            break;
        }
        it--;
        costs.erase(it);
        mult = mult * 2;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
