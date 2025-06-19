#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector<int> tree;
    int n;

    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, 0);
    }

    void update(int idx, int addend) {
        update(0, 0, n - 1, idx, addend);
    }

    void update(int treeIdx, int segLeft, int segRight, int idx, int addend) {
        if (segLeft == segRight) {
            tree[treeIdx] += addend;
            return;
        }
        int mid = (segLeft + segRight) / 2;
        if (idx <= mid) {
            update(2 * treeIdx + 1, segLeft, mid, idx, addend);
        } else {
            update(2 * treeIdx + 2, mid + 1, segRight, idx, addend);
        }
        tree[treeIdx] = tree[2 * treeIdx + 1] + tree[2 * treeIdx + 2];
    }

    int getKthElement(int k) {
        return getKthElement(0, 0, n - 1, k);
    }

    int getKthElement(int treeIdx, int segLeft, int segRight, int k) {
        if (k >= tree[treeIdx]) return -1;
        if (segLeft == segRight) return segLeft;

        int mid = (segLeft + segRight) / 2;
        int leftCount = tree[2 * treeIdx + 1];
        if (k < leftCount) {
            return getKthElement(2 * treeIdx + 1, segLeft, mid, k);
        } else {
            return getKthElement(2 * treeIdx + 2, mid + 1, segRight, k - leftCount);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    set<int> uniqueVals;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        uniqueVals.insert(arr[i]);
    }

    vector<int> sortedUnique(uniqueVals.begin(), uniqueVals.end());
    unordered_map<int, int> valToIdx;
    unordered_map<int, int> idxToVal;

    for (int i = 0; i < sortedUnique.size(); ++i) {
        valToIdx[sortedUnique[i]] = i;
        idxToVal[i] = sortedUnique[i];
    }

    SegmentTree segmentTree(sortedUnique.size());
    int left = 0, right = 0;
    vector<int> res;

    while (right < n) {
        segmentTree.update(valToIdx[arr[right]], 1);
        if (right - left + 1 == k) {
            int mid = (k - 1) / 2;
            int medianIdx = segmentTree.getKthElement(mid);
            res.push_back(idxToVal[medianIdx]);
            segmentTree.update(valToIdx[arr[left]], -1);
            left++;
        }
        right++;
    }

    for (int i = 0; i < res.size(); ++i) {
        if (i > 0) cout << " ";
        cout << res[i];
    }
    cout << "\n";

    return 0;
}