/**
 * 973
 * https://leetcode.com/problems/
 */
#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

#define len(x) static_cast<int>((x).size())

// Constants
constexpr long long MOD = 1e9 + 7;
constexpr long long INF = 1e18;
constexpr long long MAXN = 2e6 + 5; // for factorial precomputation etc.
class Solution {
public:
    int partition(int left, int right, vector<pair<long long, int> > &arr) {
        int first_greater = left;
        auto pivot = arr[right];
        for (int j = left; j < right; j++) {
            if (arr[j] <= pivot) {
                swap(arr[first_greater], arr[j]);
                first_greater++;
            }
        }
        swap(arr[first_greater], arr[right]);
        return first_greater;
    }

    vector<vector<int> > kClosest(vector<vector<int> > &points, int k) {
        vector<pair<long long, int> > dist;
        for (int i = 0; i < points.size(); i++) {
            auto &p = points[i];
            dist.emplace_back(1LL * p[0] * p[0] + p[1] * p[1], i);
        }
        int left = 0, right = points.size() - 1;
        while (left <= right) {
            int pivot_idx = partition(left, right, dist);
            if (pivot_idx == k - 1) {
                vector<vector<int> > res;
                for (int i = 0; i <= pivot_idx; i++) {
                    res.emplace_back(points[dist[i].second]);
                }
                return res;
            }
            if (pivot_idx > k - 1) {
                right = pivot_idx - 1;
            } else {
                left = pivot_idx + 1;
            }
        }
        return {};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution sol;
    // vector<int> temp{1, 2};
    // debug(sol.method(temp));

    return 0;
}
