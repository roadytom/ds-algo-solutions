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

// Reads a line from stdin and splits it into a vector of strings.
vector<string> read_words() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<string> words;
    string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}

// Reads a single line from stdin.
string read_line() {
    string line;
    if (cin.peek() == '\n') cin.ignore(); // skip leftover newline
    getline(cin, line);
    return line;
}

// Reads n lines from stdin.
vector<string> read_n_lines(int n) {
    vector<string> lines;
    for (int i = 0; i < n; ++i) {
        lines.push_back(read_line());
    }
    return lines;
}

// Reads a single integer from a line of stdin.
int read_int() {
    const string line = read_line();
    return stoi(line);
}

// Reads a space-separated list of integers from a single line of stdin.
vector<int> read_int_list() {
    const string line = read_line();
    istringstream iss(line);
    vector<int> numbers;
    int num;
    while (iss >> num) {
        numbers.push_back(num);
    }
    return numbers;
}

// Reads a space-separated list of integers and converts them to 0-indexed.
vector<int> read_int_list_0_indexed() {
    vector<int> numbers = read_int_list();
    for (int &num: numbers) {
        num--;
    }
    return numbers;
}

// Reads n lines, each with space-separated words.
vector<vector<string> > read_n_lines_words(int n) {
    vector<vector<string> > result;
    for (int i = 0; i < n; ++i) {
        result.push_back(read_words());
    }
    return result;
}

// Reads n integers, each from a new line.
vector<int> read_n_ints(int n) {
    vector<int> numbers;
    for (int i = 0; i < n; ++i) {
        numbers.push_back(read_int());
    }
    return numbers;
}

// Reads n lines, each with a space-separated list of integers.
vector<vector<int> > read_n_int_lists(int n) {
    vector<vector<int> > result;
    for (int i = 0; i < n; ++i) {
        result.push_back(read_int_list());
    }
    return result;
}

// Reads n lines, each with a space-separated list of 0-indexed integers.
vector<vector<int> > read_n_int_lists_0_indexed(int n) {
    vector<vector<int> > result;
    for (int i = 0; i < n; ++i) {
        result.push_back(read_int_list_0_indexed());
    }
    return result;
}

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
    a, b arrays
    any num of times: i (1<=i<=n-1) -> a[i] = b[i + 1] or b[i] = a[i + 1]
    once at the beginning: i (1<=i<=n) remove a[i], b[i]
    Match means: a, b arrays, num of: a[i] = b[i]
    E.X:
    2 2 2 4
    2 2 2 2

*/
int find_max_match_mine(const vector<int> &a, const vector<int> &b) {
    vector<int> a_idxs(len(a) + 1, -1);
    vector<int> b_idxs(len(a) + 1, -1);
    int max_match = 0;
    for (int i = 0; i < len(a); i++) {
        b_idxs[b[i]] = i;
        int a_idx = a_idxs[a[i]];
        int b_idx = b_idxs[a[i]];
        if (a_idx != -1) {
            max_match = max(max_match, a_idx + 1);
        }
        if (b_idx != -1) {
            if ((i - b_idx) % 2 == 1) {
                if ((i - b_idx) > 1) {
                    max_match = max(max_match, b_idx + 1);
                }
            } else {
                max_match = max(max_match, b_idx + 1);
            }
        }
        a_idxs[a[i]] = i;
    }
    return max_match;
}

int find_max_match(vector<int> &a, vector<int> &b) {
    vector<bool> a_idxs(len(a) + 1, false);
    vector<bool> b_idxs(len(a) + 1, false);
    for (int i = len(a) - 1; i >= 0; i--) {
        if (a[i] == b[i]) {
            return i + 1;
        }
        if (a_idxs[b[i]] || b_idxs[a[i]] || b_idxs[b[i]] || a_idxs[a[i]]) {
            return i + 1;
        }
        if (i + 1 < len(a) && (a[i] == a[i + 1] || b[i] == b[i + 1])) {
            return i + 1;
        }
        if (i + 1 < len(a)) {
            a_idxs[a[i + 1]] = true;
            b_idxs[b[i + 1]] = true;
        }
    }
    return 0;
}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (auto &x: a) {
        cin >> x;
    }
    for (auto &x: b) {
        cin >> x;
    }
    int max_match = find_max_match(a, b);
    print(max_match);
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
