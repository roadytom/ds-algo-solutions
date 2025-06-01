#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

const double INF = 1e18;
const int MOD = 1000000007;

vector<vector<int>> tree;
vector<int> in_time, out_time;

class SegmentTree {
private:
    vector<double> segTree;
    int n;

    void build(vector<double> &arr, int idx, int left, int right) {
        if (left == right) {
            segTree[idx] = arr[left];
            return;
        }
        int mid = (left + right) / 2;
        build(arr, 2 * idx + 1, left, mid);
        build(arr, 2 * idx + 2, mid + 1, right);
        segTree[idx] = segTree[2 * idx + 1] + segTree[2 * idx + 2];
    }

    double query(int idx, int seg_left, int seg_right, int ql, int qr) {
        if (seg_right < ql || seg_left > qr) return 0;
        if (ql <= seg_left && seg_right <= qr) return segTree[idx];
        int mid = (seg_left + seg_right) / 2;
        double left_result = query(2 * idx + 1, seg_left, mid, ql, qr);
        double right_result = query(2 * idx + 2, mid + 1, seg_right, ql, qr);
        return left_result + right_result;
    }

    void update(int idx, int seg_left, int seg_right, int pos, double new_val) {
        if (seg_left == seg_right) {
            segTree[idx] = new_val;
            return;
        }
        int mid = (seg_left + seg_right) / 2;
        if (pos <= mid)
            update(2 * idx + 1, seg_left, mid, pos, new_val);
        else
            update(2 * idx + 2, mid + 1, seg_right, pos, new_val);
        segTree[idx] = segTree[2 * idx + 1] + segTree[2 * idx + 2];
    }

public:
    SegmentTree(vector<double> &arr) {
        n = arr.size();
        segTree.resize(4 * n, 0);
        build(arr, 0, 0, n - 1);
    }

    double query(int ql, int qr) {
        return query(0, 0, n - 1, ql, qr);
    }

    void update(int pos, double new_val) {
        update(0, 0, n - 1, pos, new_val);
    }
};

int dfs(int node, int parent, int timer) {
    in_time[node] = timer;
    for (int child : tree[node]) {
        if (child == parent) continue;
        timer = dfs(child, node, timer + 1);
    }
    out_time[node] = timer;
    return timer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nodes_count;
    cin >> nodes_count;
    tree.resize(nodes_count);
    in_time.assign(nodes_count, -1);
    out_time.assign(nodes_count, -1);

    for (int i = 0; i < nodes_count - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(0, -1, 0);

    vector<double> initial(nodes_count, 0.0);
    SegmentTree segment_tree(initial);

    int q;
    cin >> q;
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        --x;
        if (t == 1) {
            int left = in_time[x];
            double log_y = log(y);
            segment_tree.update(left, log_y);
        } else {
            --y;
            int x_left = in_time[x], x_right = out_time[x];
            int y_left = in_time[y], y_right = out_time[y];
            double x_val = segment_tree.query(x_left, x_right);
            double y_val = segment_tree.query(y_left, y_right);
            double log_diff = x_val - y_val;
            double ans_log = max(log(1e-9), min(log(1e9), log_diff));
            cout << fixed << setprecision(10) << exp(ans_log) << '\n';
        }
    }

    return 0;
}