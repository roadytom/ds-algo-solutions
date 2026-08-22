/**
 * 1386
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
    int maxNumberOfFamilies(int n, vector<vector<int> > &seats) {
        sort(seats.begin(), seats.end());
        seats.push_back({n + 1, 1});

        debug(seats);
        int ans = 0;
        auto calculate_answer_in_between = [](int left, int right) {
            if ((left + 1) % 2 == 0) {
                debug(left, right, (right - left - 1) / 4);
                return (right - left - 1) / 4;
            }
            debug(left, right, 0);

            return 0;
        };
        int curr_row = 1, prev_seat = 1;
        for (auto &v: seats) {
            int row = v[0], curr_seat = v[1];
            if (row > curr_row) {
                // finalize the old row and start new row
                ans += calculate_answer_in_between(prev_seat, 10);
                ans += (row - curr_row - 1) * calculate_answer_in_between(1, 10);
                ans += calculate_answer_in_between(1, curr_seat);
                prev_seat = curr_seat;
                curr_row = row;
            } else {
                ans += calculate_answer_in_between(prev_seat, curr_seat);
                prev_seat = curr_seat;
            }
            debug(row, ans);

        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution sol;
    // vector<vector<int> > temp{{2, 10}, {3, 1}, {1, 2}, {2, 2}, {3, 5}, {4, 1}, {4, 9}, {2, 7}};
    // debug(sol.maxNumberOfFamilies(4, temp));
    // vector<vector<int> > temp{{2, 1}, {1, 8}, {2, 6}};
    // debug(sol.maxNumberOfFamilies(2, temp));

    // vector<vector<int> > temp{{1, 2}, {1, 3}, {1, 8}, {2, 6}, {3, 1}, {3, 10}};
    // debug(sol.maxNumberOfFamilies(3, temp));

    vector<vector<int> > temp{{2, 3}};
    debug(sol.maxNumberOfFamilies(3, temp));
    return 0;
}
