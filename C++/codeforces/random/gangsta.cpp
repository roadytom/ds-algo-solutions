#include <iostream>
#include <vector>
#include <string>

// Node structure for the Segment Tree
struct Node {
    long long count;
    long long sum;
};

// Segment Tree implementation using a recursive approach
struct SegmentTree {
    int size;
    std::vector<Node> tree;

    // Helper function to merge results from child nodes
    Node merge(const Node &a, const Node &b) {
        return {a.count + b.count, a.sum + b.sum};
    }

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
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
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
        return merge(s1, s2);
    }

    // Public query function to start the recursion
    Node query(int l, int r) {
        return query_recursive(l, r, 0, 0, size);
    }
};

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    // Part 1: Sum of lengths of all substrings
    long long sum_len = static_cast<long long>(n) * (n + 1) * (n + 2) / 6;

    // Part 2: Sum of absolute differences |c0 - c1|
    long long sum_diff = 0;

    int offset = n;
    int range_size = 2 * n + 1;

    SegmentTree st;
    st.init(range_size);

    // Initial state: d[0] = 0
    long long current_d = 0;
    st.update(current_d + offset, current_d);

    // Iterate through i from 1 to n
    for (int i = 1; i <= n; ++i) {
        current_d += (s[i - 1] == '0' ? 1 : -1);
        int d_idx = current_d + offset;

        // Query for d[j] values smaller than current_d
        Node less_node = st.query(0, d_idx);
        long long count_less = less_node.count;
        long long sum_less = less_node.sum;

        // Query for all d[j] values encountered so far
        Node total_node = st.query(0, range_size);
        long long count_total = total_node.count;
        long long sum_total = total_node.sum;

        long long count_geq = count_total - count_less;
        long long sum_geq = sum_total - sum_less;

        // Σ|d[i]-d[j]| = (d[i]*count_less - sum_less) + (sum_geq - d[i]*count_geq)
        sum_diff += (current_d * count_less - sum_less) + (sum_geq - current_d * count_geq);

        // Add current_d to the Segment Tree for subsequent steps
        st.update(d_idx, current_d);
    }

    //  (Σ len + Σ |c0 - c1|) / 2
    long long total_f = (sum_len + sum_diff) / 2;
    // std::cout << sum_len << " " << sum_diff << std::endl;
    std::cout << total_f << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
