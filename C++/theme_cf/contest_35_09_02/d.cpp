#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
#define len(x) static_cast<int>((x).size())
#define mp make_pair
#define mt make_tuple
#define pb push_back
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
struct data {
    // 0 -> unknown, 1 -> must be sorted, 2 -> must be unsorted;
    int state;
};

bool solve() {
    string s;
    cin >> s;
    stack<int> st;
    for (char c: s) {
        if (c == '+') {
            if (!st.empty() && st.top() == 2) {
                st.push(2);
            } else {
                st.push(0);
            }
        } else if (c == '-') {
            int top_state = st.top();
            st.pop();
            if (!st.empty() && top_state == 1 && st.top() != 1) {
                st.pop();
                st.push(1);
            }
        } else if (c == '1') {
            if (!st.empty() && st.top() == 2) {
                return false;
            }
            if (!st.empty()) {
                st.pop();
                st.push(1);
            }
        } else {
            if (len(st) <= 1 || (!st.empty() && st.top() == 1)) {
                return false;
            }
            st.pop();
            st.push(2);
        }
        debug(st);
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        if (solve()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
