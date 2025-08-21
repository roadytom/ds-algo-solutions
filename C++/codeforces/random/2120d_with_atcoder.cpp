#include <atcoder/modint>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
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

/** END OF CREATION MULTI-D VECTOR **/

/**
A: a, b, k
H: a, b, k
A -> H{n, m}
H -> A X[n][m]: elements 1 <= x <= k
A wins if can find submatrix (similar to subsequence) Y[a][b] of X: ALL elements are EQUAL
FIND lexicographically min tuple (n, m) -> A always wins
USE MOD
1. max(m, n) should include min(m, n)
2.

For the n value first:
    for the row -> I have k options
    Pigeonhole principle -> n boxes -> if I choose at least (a - 1) * k + 1, there is at least one
    element that occurred more than a
For the m value:
    at least (a - 1) * k + 1 rows needed, to make one x at least occurred at least equal to a
    x -> can be any number 1..k
    it may occur any rows combination (we only sure about the total is at least a)
    Cna
    total ways = k * CnA
    and again with Pigeonhole principle
    we need at least m = (b - 1) * (different pigeons) + 1 = m = (b - 1) * k * CnA + 1
*/
using mint = static_modint<MOD>;
void solve() {
    mint a, b, k;
    mint min_a(a);
    cin >> a >> b >> k;
    ll n = mod_add(mod_mul(a - 1, k), 1);
    ll m = 1;
    m = mod_mul(m, b - 1);
    m = mod_mul(m, k);
    precompute_factorials(a);
    for (ll num = n - a + 1; num <= n; num++) {
        m = mod_mul(m, num);
    }
    m = mod_mul(m, inv_fact[a]);
    m = mod_add(m, 1);
    cout << n << " " << m << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    precompute_factorials(MAXN);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
