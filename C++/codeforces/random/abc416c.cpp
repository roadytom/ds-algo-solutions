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
void solve_optimal(int N, int K, int X, v<string> &S) {
    // int N, K;
    // // X can be very large, so we use unsigned long long
    // unsigned long long X;
    // cin >> N >> K >> X;
    //
    // // Read the N strings into a vector
    // vector<string> S(N);
    // for (int i = 0; i < N; ++i) {
    //     cin >> S[i];
    // }

    // Convert X to a 0-indexed rank for easier calculations
    X--;

    // Sort the strings lexicographically to create our ordered "alphabet"
    sort(S.begin(), S.end());


    // ========= 2. Base Conversion =========
    // This vector will store the base-N digits of X.
    // Each digit corresponds to an index in the sorted string vector 'S'.
    vector<int> indices(K);

    // Calculate the digits by repeatedly taking the remainder and dividing by N.
    // This loop generates digits from least significant (rightmost) to most significant (leftmost).
    for (int i = K - 1; i >= 0; --i) {
        indices[i] = X % N;
        X /= N;
    }


    // ========= 3. Construct the Final String =========
    string result = "";
    // Build the result by picking strings from 'S' using the calculated indices.
    for (int i = 0; i < K; ++i) {
        result += S[indices[i]];
    }


    // ========= 4. Output =========
    cout << result << endl;
}

void solve() {
    ll n, k, x;
    cin >> n >> k >> x;
    v<string> s(n);
    rep(i, 0, n) cin >> s[i];
    v<string> all_comb;
    function<void(int, v<string> &)> dfs = [&](int idx, v<string> &curr) {
        if (idx == k) {
            string res;
            for (auto &ss: curr) {
                res += ss;
            }
            all_comb.pb(res);
            return;
        }
        for (int i = 0; i < n; i++) {
            curr.pb(s[i]);
            dfs(idx + 1, curr);
            curr.pop_back();
        }
    };
    v<string> t;
    dfs(0, t);
    sort(all(all_comb));
    cout << all_comb[x - 1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 1; i <= 9; i++) {
        v<string> ss{"a", "a", "b"};
        solve_optimal(2, 2, i, ss);
    }
    return 0;
}
