#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// Include the AtCoder Lazy Segment Tree library
#include <atcoder/lazysegtree>

using namespace std;

// --- AtCoder Library Definitions ---

constexpr int INF = INT_MAX / 2;

// S: The type of data stored in the segment tree nodes (the minimum penalty).
using S = int;
// F: The type of the lazy update operation (the value to add).
using F = int;

// op: The function to combine two data values (S). We need the minimum.
S op(S a, S b) { return min(a, b); }
// e: The identity element for the op function.
S e() { return INF; }
// mapping: How to apply a lazy update (F) to a data value (S).
S mapping(F f, S s) { return s + f; }
// composition: How to combine two lazy updates (F).
F composition(F f, F g) { return f + g; }
// id: The identity for the lazy update composition.
F id() { return 0; }

// --- Main Solver ---

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n <= 1) {
        cout << 0 << endl;
        return;
    }

    // Initialize the lazy segment tree of size n+1 (for v from 0 to n).
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(n + 2);

    // Base Case: dp[0][0] = 0.
    seg.set(a[0], 0);
    seg.set(n + 1, 0);
    for (int i = 1; i < n; ++i) {
        int current_val = a[i];
        int prev_val = a[i - 1];

        // 1. Calculate the new value for dp[i][a[i-1]]
        // Note: seg.prod(l, r) queries the range [l, r-1].
        int min_less = seg.prod(0, current_val);
        int min_ge = seg.prod(current_val, n + 2);

        int new_val_for_prev = min(min_less >= INF ? INF : min_less + 1, min_ge);

        // 2. Apply range update for Choice 1
        if (current_val > prev_val) {
            // Add 1 to all penalties.
            seg.apply(0, n + 2, 1);
        }

        // 3. Apply point update to fix the value at a[i-1]
        seg.set(prev_val, new_val_for_prev);
    }

    // The final answer is the minimum penalty across all possible final states.
    cout << seg.all_prod() << endl;
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
