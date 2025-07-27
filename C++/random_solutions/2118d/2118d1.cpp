#include <bits/stdc++.h>
using namespace std;

// Macros
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii std::pair<int, int>
#define vii std::vector<pii>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(x) static_cast<int>((x).size())
#define str(x) to_string(x)
#define list vector
#define dict map
#define print(x) cout << x << endl;
#define print10(x) cout << fixed << setprecision(10) << x << endl;
#define endl "\n"


// Constants
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;
constexpr ll MAXN = 2e6 + 5; // for factorial precomputation etc.

// Directions
ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};

ll dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
ll dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

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
    ll n, k;
    cin >> n >> k;
    vector<ll> positions(n);
    for (auto &el: positions) {
        cin >> el;
    }
    vector<ll> delays(n);
    for (auto &el: delays) {
        cin >> el;
    }
    /**
       step 1
        ---> direction (time - position) % k = r_constant, Think?
        time%k = r_constant%k + position % k
        <--- direction (time + position) % k = l_constant, Think?
        time%k = l_constant%k - position % k (ignoring sign, because it will be fixed anyway at the end)

        show red when: (time - delay) % k = 0
        --> r_constant%k + position%k - delay%k = 0
        --> r_costant%k = delay%k - position%k !!! USE THIS FACT AND STORE TRAFFIC FOR R CONSTANT
        **/
    map<ll, vector<ll> > left_turn, right_turn;
    map<ll, ll> traffic_delay;
    for (int i = 0; i < n; i++) {
        ll r_constant = (delays[i] - positions[i] + k) % k;
        ll l_constant = (delays[i] + positions[i]) % k;
        right_turn[r_constant].emplace_back(positions[i]);
        left_turn[l_constant].emplace_back(positions[i]);
        traffic_delay[positions[i]] = delays[i];
    }

    /**
      step 2
      using this constant maps, we can find next positions effectively
      For example, if at TIME, we at POSITION, turning to R what is my NEXT RED LIGHT
      1. get all red light traffic positions for the constant (TIME - POSTION) % k
      find the earliest next positions for my POSITION
       **/
    auto get_next_right = [&](ll pos, ll time) {
        ll r_constant = (time - pos + k) % k;
        auto &vec = right_turn[r_constant];
        auto it = lower_bound(vec.begin(), vec.end(), pos + 1);
        if (it == vec.end()) {
            return -1ll;
        }
        return *it;
    };
    auto get_next_left = [&](ll pos, ll time) {
        ll l_constant = (pos + time) % k;
        auto &vec = left_turn[l_constant];
        auto it = lower_bound(vec.begin(), vec.end(), pos);
        if (it == vec.begin()) {
            return -1ll;
        }
        it--;
        return *it;
    };

    int query;
    cin >> query;

    map<pair<ll, ll>, bool> dp;
    while (query--) {
        ll curr_position;
        cin >> curr_position;
        int direction = 1;
        ll curr_time = 0;

        bool ok = false;
        set<pair<ll, ll> > seen;


        if (traffic_delay.count(curr_position) && traffic_delay[curr_position] == 0) {
            direction ^= 1;
        }
        for (int it = 0; it < 2 * n; it++) {
            ll next_position = direction
                                   ? get_next_right(curr_position, curr_time)
                                   : get_next_left(curr_position, curr_time);
            if (next_position == -1) {
                ok = true;
                break;
            }
            curr_time += abs(curr_position - next_position);
            curr_position = next_position;
            direction ^= 1;
            if (seen.count({curr_position, direction}))
                break;
            seen.insert({curr_position, direction});

            if (dp.count({curr_position, direction})) {
                ok = dp[{curr_position, direction}];
                break;
            }
        }
        for (auto [a, b]: seen) {
            dp[{a, b}] = ok;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
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
