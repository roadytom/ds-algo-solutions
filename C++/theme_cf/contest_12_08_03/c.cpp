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


// struct SegmentTree {
//     int size{};
//     std::vector<int> tree;
//
//     // Helper function to merge results from child ints
//
//     void init(int n) {
//         size = 1;
//         while (size < n) size *= 2;
//         tree.assign(2 * size, 1);
//     }
//
//     // Private recursive helper for updates
//     void update_recursive(int idx, long long val, int x, int lx, int rx) {
//         if (rx - lx == 1) {
//             // Base case: we are at a leaf int
//             tree[x] = val;
//             return;
//         }
//
//         int m = (lx + rx) / 2;
//         // Recursive step: go left or right
//         if (idx < m) {
//             update_recursive(idx, val, 2 * x + 1, lx, m);
//         } else {
//             update_recursive(idx, val, 2 * x + 2, m, rx);
//         }
//
//         // After the recursive call returns, update the current int
//         tree[x] = tree[2 * x + 1] & tree[2 * x + 2];
//     }
//
//     // Public update function to start the recursion
//     void update(int idx, long long val) {
//         update_recursive(idx, val, 0, 0, size);
//     }
//
//     // Private recursive helper for queries
//     int query_recursive(int l, int r, int x, int lx, int rx) {
//         // Base case 1: The int's range is completely outside the query range
//         if (lx >= r || l >= rx) return 1;
//         // Base case 2: The int's range is completely inside the query range
//         if (lx >= l && rx <= r) return tree[x];
//
//         // Recursive step: query children and merge the results
//         int m = (lx + rx) / 2;
//         int s1 = query_recursive(l, r, 2 * x + 1, lx, m);
//         int s2 = query_recursive(l, r, 2 * x + 2, m, rx);
//         return s1 & s2;
//     }
//
//     // Public query function to start the recursion
//     int query(int l, int r) {
//         return query_recursive(l, r, 0, 0, size);
//     }
// };

class SegmentAndTree {
private:
    // The vector to store the segment tree nodes
    std::vector<int> segment_tree;
    // The size of the original input array
    int length;

    /**
     * @brief Iteratively builds the segment tree from the input array.
     * @param arr The input array.
     */
    void build(const std::vector<int>& arr) {
        // Insert leaf nodes in the second half of the tree array
        for (int i = 0; i < length; i++) {
            segment_tree[length + i] = arr[i];
        }

        // Build the tree bottom-up by calculating parent nodes
        for (int i = length - 1; i > 0; --i) {
            // Parent is the AND of its two children
            segment_tree[i] = segment_tree[i * 2] & segment_tree[i * 2 + 1];
        }
    }

public:
    /**
     * @brief Constructor for the SegmentAndTree.
     * @param arr The input array to build the segment tree from.
     */
    SegmentAndTree(const std::vector<int>& arr) {
        length = arr.size();
        // Allocate 2 times the size for the segment tree.
        // Index 0 is unused to make parent/child calculations simpler (1-based indexing).
        segment_tree.resize(2 * length);
        build(arr);
    }

    /**
     * @brief Public method to update a value at a specific position (iterative).
     * @param pos The 0-based position in the original array to update.
     * @param new_val The new value.
     */
    void update(int pos, int new_val) {
        // Move to the leaf node position
        pos += length;
        segment_tree[pos] = new_val;

        // Update the path to the root by recalculating parent nodes
        while (pos > 1) {
            pos /= 2; // Move to the parent
            segment_tree[pos] = segment_tree[pos * 2] & segment_tree[pos * 2 + 1];
        }
    }

    /**
     * @brief Public method to query the bitwise AND of a range [left, right] (iterative).
     * @param left The starting index of the query range (inclusive).
     * @param right The ending index of the query range (inclusive).
     * @return The bitwise AND of the elements in the range.
     */
    int range_and(int left, int right) {
        int res = ~0; // Identity for bitwise AND (all bits set to 1)

        // Move to the leaf nodes, loop until the pointers cross
        for (left += length, right += length; left <= right; left /= 2, right /= 2) {
            // If left pointer is a right child, include its value and move to the right
            if (left % 2 == 1) {
                res &= segment_tree[left++];
            }
            // If right pointer is a left child, include its value and move to the left
            if (right % 2 == 0) {
                res &= segment_tree[right--];
            }
        }
        return res;
    }


};
void solve() {
    int n;
    cin >> n;
    vector<int> p;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p.push_back(x);
    }
    SegmentAndTree t(p);
    // debug(t.segment_tree);
    int q;
    cin >> q;
    // int temp = t.range_and(0, 2);
    // debug(temp);
    while (q--) {
        int l, k;
        cin >> l >> k;
        l--;
        int left = l;
        int right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int mid_and = t.range_and(l, mid);
            // debug(mid_and);
            if (mid_and < k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (right < l) {
            cout << -1 << " ";
        } else {
            cout << right + 1 << " ";
        }
    }
    cout << endl;
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
