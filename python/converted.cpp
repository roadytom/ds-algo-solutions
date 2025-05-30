#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = INT_MAX;

// Direction arrays
vector<vector<int>> dire = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<vector<int>> dire8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
string alphabets = "abcdefghijklmnopqrstuvwxyz";
string ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

class SegmentTree {
public:
    int size;
    vector<int> tree;
    unordered_map<int, int> tree_idx_to_val;

    SegmentTree(const vector<int>& arr) {
        size = arr.size();
        tree.resize(4 * size, 0);
        build_tree(0, 0, size - 1, arr);
    }

    void build_tree(int idx, int seg_left, int seg_right, const vector<int>& arr) {
        if (seg_left == seg_right) {
            tree[idx] = 1;
            tree_idx_to_val[idx] = arr[seg_left];
            return;
        }
        int mid = (seg_left + seg_right) / 2;
        build_tree(2 * idx + 1, seg_left, mid, arr);
        build_tree(2 * idx + 2, mid + 1, seg_right, arr);
        tree[idx] = seg_right - seg_left + 1;
    }

    int find_kth_idx(int idx, int seg_left, int seg_right, int k) {
        if (k >= tree[idx]) return -1;
        if (seg_left == seg_right) return seg_left;

        int mid = (seg_left + seg_right) / 2;
        if (k < tree[2 * idx + 1]) {
            return find_kth_idx(2 * idx + 1, seg_left, mid, k);
        } else {
            return find_kth_idx(2 * idx + 2, mid + 1, seg_right, k - tree[2 * idx + 1]);
        }
    }

    int set_zero_and_get_value(int tree_idx, int seg_left, int seg_right, int idx) {
        if (idx < seg_left || idx > seg_right) throw runtime_error("index out of range");
        if (seg_left == seg_right) {
            int val = tree_idx_to_val[tree_idx];
            tree[tree_idx] = 0;
            return val;
        }
        int mid = (seg_left + seg_right) / 2;
        int result;
        if (idx <= mid) {
            result = set_zero_and_get_value(2 * tree_idx + 1, seg_left, mid, idx);
        } else {
            result = set_zero_and_get_value(2 * tree_idx + 2, mid + 1, seg_right, idx);
        }
        tree[tree_idx] = tree[2 * tree_idx + 1] + tree[2 * tree_idx + 2];
        return result;
    }
};

// Helper read functions
int read_int() {
    int x;
    cin >> x;
    return x;
}

vector<int> read_int_list(int n = -1) {
    vector<int> result;
    if (n == -1) {
        string line;
        getline(cin >> ws, line);
        stringstream ss(line);
        int x;
        while (ss >> x) result.push_back(x);
    } else {
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            result.push_back(x);
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = read_int();
    vector<int> arr = read_int_list(n);

    SegmentTree sg(arr);

    vector<int> removals = read_int_list();
    for (int idx : removals) {
        int kth_idx = sg.find_kth_idx(0, 0, sg.size - 1, idx - 1);
        int val = sg.set_zero_and_get_value(0, 0, sg.size - 1, kth_idx);
        cout << val << "\n";
    }

    return 0;
}