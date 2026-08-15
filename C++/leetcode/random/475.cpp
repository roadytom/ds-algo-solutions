/**
 * 475.Heaters
 * https://leetcode.com/problems/
 */
#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

// Macros
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii std::pair<int, int>
#define vii std::vector<pii>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define print(x) cout << x << endl;
#define print10(x) cout << fixed << setprecision(10) << x << endl;
#define endl "\n"
#define len(x) static_cast<int>((x).size())
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define v vector

// Constants
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e18;
constexpr ll MAXN = 2e6 + 5; // for factorial precomputation etc.

class Solution {
public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        sort(all(houses));
        sort(all(heaters));
        ll left = 0, right = 1e9 + 7;
        while (left <= right) {
            ll mid = (left + right) / 2;
            if (possible(houses, heaters, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool possible(vi &houses, vi &heaters, int radius) {
        int ptr1 = 0, ptr2 = 0;
        while (ptr1 < len(houses) && ptr2 < len(heaters)) {
            int curr_heaters = heaters[ptr2], curr_house = houses[ptr1];
            if (curr_heaters - radius > curr_house) {
                return false;
            }
            if (curr_heaters + radius < curr_house) {
                ptr2++;
            } else {
                ptr1++;
            }
        }
        return ptr1 >= len(houses);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solution sol;
    vi houses{1,5};
    vi heaters{2};
    debug(sol.findRadius(houses, heaters));

    return 0;
}
