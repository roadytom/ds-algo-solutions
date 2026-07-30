#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
#define len(x) static_cast<int>((x).size())
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define v vector

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
/**

*/
const int MAXN = 1e5 + 5;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int> &nums) {
        vector<int> st;
        for (int x: nums) {
            st.push_back(x);
            // Try to merge as long as the last two elements are not coprime
            while (st.size() >= 2) {
                int a = st[st.size() - 2];
                int b = st.back();
                int g = __gcd(a, b);
                if (g == 1) break; // coprime, no merge
                // Merge last two elements
                st.pop_back();
                st.back() = (int) (1LL * a * b / g);
            }
        }
        return st;
    }

    // int main() {
    //     ios::sync_with_stdio(false);
    //     cin.tie(nullptr);
    //     cout.tie(nullptr);
    //     Solution s;
    //     v<int> temp{6, 4, 3, 2, 7, 6, 2};
    //     debug(s.replaceNonCoprimes(temp));
    //     return 0;
    // }
};
