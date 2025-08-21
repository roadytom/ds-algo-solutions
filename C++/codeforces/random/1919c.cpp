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
// O(N * N)
void solve_raw_dp() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int inf = INT_MAX / 2;
    vector<int> dp(n + 2, inf);
    dp[n + 1] = 0;
    dp[a[0]] = 0;
    for (int i = 1; i < n; i++) {
        vector<int> new_dp(n + 2, inf);

        for (int v = 1; v <= n + 1; v++) {
            if (dp[v] >= inf) {
                continue;
            }
            // choice 1:
            int choice1 = dp[v] + (a[i - 1] < a[i]);
            int choice2 = dp[v] + (v < a[i]);
            new_dp[v] = min(new_dp[v], choice1);
            new_dp[a[i - 1]] = min(new_dp[a[i - 1]], choice2);
        }
        dp = new_dp;
    }
    // debug(dp);
    cout << *min_element(all(dp)) << endl;
}

struct Node {
    long long count;
    long long sum;

    [[nodiscard]] Node merge(const Node &b) const {
        return {this->count + b.count, this->sum + b.sum};
    }
};

struct SegmentTree {
    int size;
    std::vector<Node> tree;

    // // Helper function to merge results from child nodes
    // Node merge(const Node &a, const Node &b) {
    //     return {a.count + b.count, a.sum + b.sum};
    // }

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, {0, 0});
    }

    // Private recursive helper for updates
    void update_recursive(int idx, long long val, int x, int lx, int rx) {
        if (rx - lx == 1) {
            // Base case: we are at a leaf node
            tree[x].count += 1;
            tree[x].sum += val;
            return;
        }

        int m = (lx + rx) / 2;
        // Recursive step: go left or right
        if (idx < m) {
            update_recursive(idx, val, 2 * x + 1, lx, m);
        } else {
            update_recursive(idx, val, 2 * x + 2, m, rx);
        }

        // After the recursive call returns, update the current node
        tree[x] = tree[2 * x + 1].merge(tree[2 * x + 2]);
    }

    // Public update function to start the recursion
    void update(int idx, long long val) {
        update_recursive(idx, val, 0, 0, size);
    }

    // Private recursive helper for queries
    Node query_recursive(int l, int r, int x, int lx, int rx) {
        // Base case 1: The node's range is completely outside the query range
        if (lx >= r || l >= rx) return {0, 0};
        // Base case 2: The node's range is completely inside the query range
        if (lx >= l && rx <= r) return tree[x];

        // Recursive step: query children and merge the results
        int m = (lx + rx) / 2;
        Node s1 = query_recursive(l, r, 2 * x + 1, lx, m);
        Node s2 = query_recursive(l, r, 2 * x + 2, m, rx);
        return s1.merge(s2);
    }

    // Public query function to start the recursion
    Node query(int l, int r) {
        return query_recursive(l, r, 0, 0, size);
    }
};

// WITH SEGMENT TREE OPTIMIZATION
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int inf = INT_MAX / 2;
    vector<int> dp(n + 2, inf);
    dp[n + 1] = 0;
    dp[a[0]] = 0;
    for (int i = 1; i < n; i++) {
        vector<int> new_dp(n + 2, inf);

        for (int v = 1; v <= n + 1; v++) {
            if (dp[v] >= inf) {
                continue;
            }
            // choice 1:
            int choice1 = dp[v] + (a[i - 1] < a[i]);
            int choice2 = dp[v] + (v < a[i]);
            new_dp[v] = min(new_dp[v], choice1);
            new_dp[a[i - 1]] = min(new_dp[a[i - 1]], choice2);
        }
        dp = new_dp;
    }
    // debug(dp);
    cout << *min_element(all(dp)) << endl;
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
