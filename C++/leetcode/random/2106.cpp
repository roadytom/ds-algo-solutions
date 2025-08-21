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
class Solution {
public:
    int maxTotalFruits(vector<vector<int> > &fruits, int start_pos, int k) {
        vector<int> positions(2e5 + 5);
        for (auto &fruit: fruits) {
            positions[fruit[0]] += fruit[1];
        }
        vector<ll> prefix_sum(2e5 + 6, 0);
        for (int i = 0; i < 2e5 + 5; ++i) {
            prefix_sum[i + 1] = prefix_sum[i] + positions[i];
        }

        auto get_sum = [&](int l, int r) {
            if (l > r) return 0LL;
            l = max(0, l);
            r = min(r, (int) positions.size() - 1);
            return prefix_sum[r + 1] - prefix_sum[l];
        };

        ll ans = 0LL;

        // Case 1: Go right first, then optionally left
        for (int r = 0; r <= k; ++r) {
            int l = max(0, (k - 2 * r)); // Remaining steps allow for a left move of l
            ans = max(ans, get_sum(start_pos - l, start_pos + r));

            l = max(0, (k - r) / 2); // Or, go left first then right
            ans = max(ans, get_sum(start_pos - l, start_pos + r));
        }

        // Case 2: Go left first, then optionally right
        for (int l = 0; l <= k; ++l) {
            int r = max(0, (k - 2 * l)); // Remaining steps allow for a right move of r
            ans = max(ans, get_sum(start_pos - l, start_pos + r));

            r = max(0, (k - l) / 2); // Or, go right first then left
            ans = max(ans, get_sum(start_pos - l, start_pos + r));
        }

        return (int) ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    vector<vector<int> > temp = {
        {0, 15}, {3, 56}, {4, 98}, {5, 81}, {7, 16}, {8, 77}, {9, 89}, {12, 82}, {13, 49}, {14, 59}, {17, 40}, {18, 83},
        {19, 35}, {20, 31}, {21, 44}, {22, 92}, {25, 84}, {26, 42}, {29, 4}, {33, 78}, {35, 83}, {36, 3}, {37, 71},
        {41, 24}, {44, 81}, {45, 35}, {46, 81}, {48, 81}, {50, 85}, {52, 32}, {53, 93}, {54, 89}, {55, 82}, {56, 60},
        {59, 52}, {62, 79}, {63, 90}, {64, 41}, {66, 15}, {68, 43}, {69, 32}, {70, 51}, {71, 79}, {75, 39}, {76, 21},
        {78, 16}, {79, 44}, {80, 73}, {81, 95}, {83, 95}, {85, 11}, {87, 80}, {88, 2}, {90, 89}, {99, 35}, {100, 95}
    };
    int start_pos = 86;
    int k = 107;
    cout << s.maxTotalFruits(temp, start_pos, k) << endl;
    return 0;
}
