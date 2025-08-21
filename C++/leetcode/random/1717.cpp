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
    int maximumGain(const string &s, int x, int y) {
        int n = (int) s.size();
        pair<string, int> first{"ab", x};
        pair<string, int> second{"ba", y};
        if (x > y) {
            swap(first, second);
            swap(x, y);
        }
        stack<char> st;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!st.empty() && st.top() == second.first[0] && s[i] == second.first[1]) {
                st.pop();
                ans += y;
            } else {
                st.push(s[i]);
            }
        }
        string left;
        while (!st.empty()) {
            left += st.top();
            st.pop();
        }
        reverse(all(left));
        stack<char> second_stack;
        for (char i : left) {
            if (!st.empty() && st.top() == first.first[0] && i == first.first[1]) {
                st.pop();
                ans += x;
            } else {
                st.push(i);
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    string temp =
            "aabbabkbbbfvybssbtaobaaaabataaadabbbmakgabbaoapbbbbobaabvqhbbzbbkapabaavbbeghacabamdpaaqbqabbjbababmbakbaabajabasaabbwabrbbaabbafubayaazbbbaababbaaha";
    int x = 1926;
    int y = 4320;
    cout << s.maximumGain(temp, x, y) << endl;
    return 0;
}
