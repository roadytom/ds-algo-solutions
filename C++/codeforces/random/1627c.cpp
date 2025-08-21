#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
/**

*/
constexpr int MAXN = 2e5 + 4;
bool not_primes[MAXN]{};

vector<pair<int, int> > is_creatable(int prime) {
    vector<pair<int, int> > ans;
    for (int i = 3; i * i < prime; i++) {
        if (!not_primes[i] && !not_primes[prime - i]) {
            ans.emplace_back(i, prime - i);
        }
    }
    return ans;
}

vector<pair<int, vector<pair<int, int> > > > creatable_primes{};

void brute() {
    not_primes[0] = not_primes[1] = true;
    for (int prime = 2; prime < MAXN; prime++) {
        if (!not_primes[prime]) {
            for (int j = 2 * prime; j < MAXN; j += prime) {
                not_primes[j] = true;
            }
        }
    }
    debug(not_primes);
    for (int prime = 2; prime < MAXN; prime++) {
        if (!not_primes[prime]) {
            auto res = is_creatable(prime);
            if (!res.empty()) {
                creatable_primes.emplace_back(prime, res);
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<pair<int, int> > > tree(n + 1);
    rep(i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(pair<int, int>{i, b});
        tree[b].push_back(pair<int, int>{i, a});
    }
    int root = -1;
    rep(node, 1, n + 1) {
        if (tree[node].size() == 1) {
            root = node;
        }
        if (tree[node].size() > 2) {
            cout << -1 << endl;
            return;
        }
    }
    assert(root != -1);
    vector<int> ans(n - 1);
    vector<int> options{2, 5};
    int idx = 0;
    debug(root);
    function<void(int, int)> dfs = [&](int node, int parent) {
        for (auto &[edge_idx, child]: tree[node]) {
            if (child == parent) {
                continue;
            }
            debug(idx, edge_idx);
            ans[edge_idx] = options[idx];
            idx = (idx + 1) % 2;
            dfs(child, node);
        }
    };
    dfs(root, -1);
    debug(ans);
    for (int i = 0; i < n - 1; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    // brute();
    // debug(creatable_primes.size());
    // debug(creatable_primes);
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
