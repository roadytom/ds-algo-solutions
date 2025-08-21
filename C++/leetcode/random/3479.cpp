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
struct SegmentTree {
    int tree_length;
    int length;
    vector<int> tree;

    void build_tree(int idx, int left, int right, const vector<int> &arr) {
        if (left == right) {
            debug(idx, arr[left]);
            tree[idx] = arr[left];
        } else {
            int mid = (left + right) / 2;
            build_tree(2 * idx, left, mid, arr);
            build_tree(2 * idx + 1, mid + 1, right, arr);
            tree[idx] = max(tree[2 * idx], tree[2 * idx + 1]);
        }
    }

    explicit SegmentTree(const vector<int> &arr) {
        int n = (int) arr.size();
        length = n;
        tree_length = 4 * n;
        tree.resize(tree_length);
        build_tree(1, 0, length - 1, arr);
    }

    int do_find_left_most_greater_and_mark(int idx, int left, int right, int threshold) {
        if (tree[idx] < threshold) {
            return -1;
        }
        if (left == right) {
            tree[idx] = -1;
            return left;
        }
        int mid = (left + right) / 2;
        int res = do_find_left_most_greater_and_mark(2 * idx, left, mid, threshold);
        if (res == -1) {
            res = do_find_left_most_greater_and_mark(2 * idx + 1, mid + 1, right, threshold);
        }
        tree[idx] = max(tree[2 * idx], tree[2 * idx + 1]);
        return res;
    }

    int find_left_most_greater_and_mark(int threshold) {
        return do_find_left_most_greater_and_mark(1, 0, length - 1, threshold);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
        SegmentTree s(baskets);
        // debug(s.tree);
        int count = 0;
        for (int fruit: fruits) {
            int res = s.find_left_most_greater_and_mark(fruit);
            // cout << res << endl;
            if (res == -1) count++;
        }
        return count;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    vector<int> fruits{3, 6, 1};
    vector<int> baskets{6, 4, 7};
    cout << s.numOfUnplacedFruits(fruits, baskets) << endl;
    return 0;
}
