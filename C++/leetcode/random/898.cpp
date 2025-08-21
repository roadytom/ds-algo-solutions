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
        int subarrayBitwiseORs(vector<int> &nums) {
            set<int> elements;
            elements.insert(0);
            int count = 0;
            bool zero_found = false;
            for (int num : nums) {
                if (num == 0) zero_found = true;
                set<int> new_elements;
                for (auto el: elements) {
                    if (!elements.count(el | num) && !new_elements.count(el | num)) {
                        count++;
                    }
                    new_elements.insert(el | num);

                }
                elements = new_elements;
                elements.insert(0);
            }
            return count + zero_found;
        }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    vector<int> temp{1,1,2};
    cout << s.subarrayBitwiseORs(temp) << endl;
    return 0;
}
