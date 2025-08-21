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
    vector<int> smallestSubarrays(vector<int> &nums) {
        map<int, int> curr;
        int n = (int) nums.size();
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--) {
            map<int, int> next;
            next[nums[i]] = i;
            for (auto &[val, idx]: curr) {
                int new_one = val | nums[i];
                if (next.count(new_one)) {
                    next[new_one] = min(next[new_one], idx);
                } else {
                    next[new_one] = idx;
                }

            }
            res[i] = next.rbegin()->second - i + 1;
            curr = next;
            debug(curr);
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    vector<int> temp{1, 0, 2, 1, 3};
    debug(s.smallestSubarrays(temp));
    return 0;
}
