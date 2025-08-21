#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define ll long long int
using namespace std;

constexpr ll INF = LLONG_MAX / 2;

// Segment Tree Node
struct Node {
    ll min_val;
    ll lazy_add;
};

vector<Node> tree;
int N_segtree;

// Function to merge two nodes
Node merge(const Node &left, const Node &right) {
    return {min(left.min_val, right.min_val), 0};
}

// Push lazy updates down to children
void push(int node_idx) {
    if (tree[node_idx].lazy_add != 0) {
        // Apply lazy value to current node's min_val
        tree[node_idx].min_val += tree[node_idx].lazy_add;
        // If not a leaf, pass lazy value to children
        if (node_idx * 2 + 1 < tree.size()) {
            tree[node_idx * 2].lazy_add += tree[node_idx].lazy_add;
            tree[node_idx * 2 + 1].lazy_add += tree[node_idx].lazy_add;
        }
        tree[node_idx].lazy_add = 0;
    }
}

// Build the segment tree
void build(int node_idx, int l, int r) {
    if (l == r) {
        // Base case: dp[0][0] = 0, others are INF
        tree[node_idx] = {(l == 0) ? 0 : INF, 0};
        return;
    }
    int mid = l + (r - l) / 2;
    build(node_idx * 2, l, mid);
    build(node_idx * 2 + 1, mid + 1, r);
    tree[node_idx] = merge(tree[node_idx * 2], tree[node_idx * 2 + 1]);
}

// Range Update: Add 'val' to all elements in [start, end]
void range_update(int node_idx, int l, int r, int start, int end, ll val) {
    push(node_idx);
    if (l > end || r < start) {
        return;
    }
    if (l >= start && r <= end) {
        tree[node_idx].lazy_add += val;
        push(node_idx);
        return;
    }
    int mid = l + (r - l) / 2;
    range_update(node_idx * 2, l, mid, start, end, val);
    range_update(node_idx * 2 + 1, mid + 1, r, start, end, val);

    // After updating children, re-calculate current node's value
    push(node_idx * 2);
    push(node_idx * 2 + 1);
    tree[node_idx] = merge(tree[node_idx * 2], tree[node_idx * 2 + 1]);
}

// Point Update: Set element at 'pos' to 'val'
void point_update(int node_idx, int l, int r, int pos, ll val) {
    push(node_idx);
    if (l == r) {
        tree[node_idx].min_val = val;
        return;
    }
    int mid = l + (r - l) / 2;
    // Push updates to children before traversing
    push(node_idx * 2);
    push(node_idx * 2 + 1);
    if (pos <= mid) {
        point_update(node_idx * 2, l, mid, pos, val);
    } else {
        point_update(node_idx * 2 + 1, mid + 1, r, pos, val);
    }

    // After updating children, re-calculate current node's value
    push(node_idx * 2);
    push(node_idx * 2 + 1);
    tree[node_idx] = merge(tree[node_idx * 2], tree[node_idx * 2 + 1]);
}


// Range Query: Find minimum in [start, end]
ll range_query(int node_idx, int l, int r, int start, int end) {
    if (l > end || r < start) {
        return INF;
    }
    push(node_idx);
    if (l >= start && r <= end) {
        return tree[node_idx].min_val;
    }
    int mid = l + (r - l) / 2;
    ll p1 = range_query(node_idx * 2, l, mid, start, end);
    ll p2 = range_query(node_idx * 2 + 1, mid + 1, r, start, end);
    return min(p1, p2);
}

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

    N_segtree = n + 2;
    tree.assign(4 * N_segtree, {INF, 0LL});
    build(1, 0, N_segtree - 1);
    point_update(1, 0, N_segtree - 1, a[0], 0LL);
    point_update(1, 0, N_segtree - 1, n + 1, 0LL);
    for (int i = 1; i < n; ++i) {
        int current_val = a[i];
        int prev_val = a[i - 1];

        // 1. Calculate the new value for dp[i][a[i-1]]
        ll min_less = INF;
        if (current_val > 0) {
            min_less = range_query(1, 0, N_segtree - 1, 0, current_val - 1);
        }
        ll min_ge = range_query(1, 0, N_segtree - 1, current_val, n + 1);

        ll new_val_for_prev = min(min_less >= INF ? INF : min_less + 1, min_ge);

        // 2. Apply range update for Choice 1
        if (current_val > prev_val) {
            range_update(1, 0, N_segtree - 1, 0, n + 1, 1);
        }

        // 3. Apply point update to fix the value at a[i-1]
        point_update(1, 0, N_segtree - 1, prev_val, new_val_for_prev);
    }

    cout << range_query(1, 0, N_segtree - 1, 0, n + 1) << endl;
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
