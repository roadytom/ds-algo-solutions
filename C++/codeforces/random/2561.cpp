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
/**
2 2 4   2
2   4 1 1

basket1 = [4,2,2,2], basket2 = [1,4,1,2]
*/
class Solution {
public:
    long long minCost(vector<int> &basket1, vector<int> &basket2) {
        unordered_map<int, ll> counter;
        for (auto &num: basket1) {
            counter[num]++;
        }
        for (auto &num: basket2) {
            counter[num]--;
        }
        vector<int> swap_elements;
        int min_val = INT_MAX;
        for (auto [num, cost]: counter) {
            if (abs(cost) % 2 != 0) {
                return -1;
            }
            for (int i = 0; i < abs(cost) / 2; i++) {
                swap_elements.push_back(num);
            }
            min_val = min(min_val, num);
        }
        sort(all(swap_elements));
        int left = 0, right = (int) swap_elements.size() - 1;
        ll cost = 0;
        while (left < right) {
            cost += 1LL * min(swap_elements[left], 2 * min_val);
            left++;
            right--;
        }
        return cost;
    }
};
int main() {

}