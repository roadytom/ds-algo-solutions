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
#define endl "\n"
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)


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
class Solution {
public:
    int nodes_count{};
    vector<int> depth;
    vector<int> xors;
    vector<vector<int> > tree;
    vector<int> *nums_ptr{};
    int timer = 0;
    vector<int> in, out;

    int get_subtree_node_using_cut_edge(vector<int> &edge) {
        if (depth[edge[0]] > depth[edge[1]]) {
            return edge[0];
        }
        return edge[1];
    }

    void build_tree(vector<vector<int> > &edges) {
        for (auto &edge: edges) {
            int a = edge[0], b = edge[1];
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
    }

    void dfs(int node, int parent) {
        in[node] = ++timer;
        xors[node] = (*nums_ptr)[node];
        for (int child: tree[node]) {
            if (child == parent) continue;
            depth[child] = depth[node] + 1;
            dfs(child, node);
            xors[node] ^= xors[child];
        }
        out[node] = ++timer;
    }

    bool is_ancestor(int u, int v) {
        return in[u] <= in[v] && out[v] <= out[u];
    }

    int minimumScore(vector<int> &nums, vector<vector<int> > &edges) {
        nodes_count = (int) nums.size();
        xors.resize(nodes_count);
        depth.resize(nodes_count);
        tree.resize(nodes_count);
        in.resize(nodes_count);
        out.resize(nodes_count);
        nums_ptr = &nums;
        build_tree(edges);
        dfs(0, -1);
        int min_score = INT_MAX;
        for (int i = 0; i < nodes_count - 1; i++) {
            for (int j = i + 1; j < nodes_count - 1; j++) {
                int bottom_node = get_subtree_node_using_cut_edge(edges[i]);
                int top_node = get_subtree_node_using_cut_edge(edges[j]);
                if (depth[bottom_node] < depth[top_node]) {
                    swap(bottom_node, top_node);
                }
                int top_xor, bottom_xor, third_xor;
                if (is_ancestor(top_node, bottom_node)) {
                    top_xor = xors[top_node] ^ xors[bottom_node];
                    bottom_xor = xors[bottom_node];
                    third_xor = xors[0] ^ xors[top_node];
                } else {
                    top_xor = xors[top_node];
                    bottom_xor = xors[bottom_node];
                    third_xor = xors[0] ^ top_xor ^ bottom_xor;
                }
                int score = max(top_xor, max(bottom_xor, third_xor)) - min(top_xor, min(bottom_xor, third_xor));
                min_score = min(min_score, score);
            }
        }
        return min_score;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    vector<int> nums{1, 5, 5, 4, 11};
    vector<vector<int> > edges{{0, 1}, {1, 2}, {1, 3}, {3, 4}};
    cout << s.minimumScore(nums, edges) << endl;
    print_vector(s.xors);
    print_vector(s.depth);
    print_vector(s.in);
    print_vector(s.out);
    for (int i = 0; i < nums.size(); i++) {
        print_vector(s.tree[i]);
    }
    return 0;
}
