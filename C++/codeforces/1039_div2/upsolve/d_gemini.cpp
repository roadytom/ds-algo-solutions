#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// A value greater than any possible index, used as infinity.
const int INF_SENTINEL = 500000 + 2;

// Segment Tree for Range Minimum Query
struct SegTree {
    int n;
    vector<int> t;

    SegTree(int size) {
        n = size;
        t.assign(4 * n + 5, INF_SENTINEL);
    }

    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = min(t[v], new_val); // Update by taking minimum
            return;
        }
        int tm = tl + (tr - tl) / 2;
        if (pos <= tm) {
            update(v * 2, tl, tm, pos, new_val);
        } else {
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        }
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return INF_SENTINEL;
        }
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = tl + (tr - tl) / 2;
        return min(query(v * 2, tl, tm, l, min(r, tm)),
                   query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    void update(int pos, int new_val) {
        update(1, 1, n, pos, new_val);
    }

    int query(int l, int r) {
        if (l > n) return INF_SENTINEL;
        return query(1, 1, n, l, r);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    long long total_subarrays = (long long) n * (n + 1) / 2;

    // Start with N_{>=1}
    long long ans = total_subarrays;

    // Add N_{>=2} = total_subarrays - num_increasing_subarrays
    long long increasing_subarrays = 0;
    int current_increasing_len = 0;
    for (int i = 1; i <= n; ++i) {
        if (i > 1 && p[i] > p[i - 1]) {
            current_increasing_len++;
        } else {
            current_increasing_len = 1;
        }
        increasing_subarrays += current_increasing_len;
    }
    ans += total_subarrays - increasing_subarrays;

    // Add N_{>=3}

    // Step 1: Compute pg[j] = min {i | i < j, p_i > p_j}
    vector<int> pg(n + 1, n + 1);
    SegTree st_pg(n);
    for (int j = 1; j <= n; ++j) {
        pg[j] = st_pg.query(p[j] + 1, n);
        st_pg.update(p[j], j);
    }

    // Step 2: Compute F[k] = min { pg[j] | j < k, p_j > p_k }
    vector<int> F(n + 1, n + 1);
    SegTree st_F(n);
    for (int k = 1; k <= n; ++k) {
        F[k] = st_F.query(p[k] + 1, n);
        if (pg[k] <= n) {
            // Only update with valid indices
            st_F.update(p[k], pg[k]);
        }
    }

    // Step 3: Compute N_{>=3} = sum_{r=1..n} l_0(r)
    long long n_ge_3 = 0;
    int min_l = n + 1;
    for (int r = 1; r <= n; ++r) {
        min_l = min(min_l, F[r]);
        if (min_l <= n) {
            n_ge_3 += min_l;
        }
    }
    ans += n_ge_3;

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
