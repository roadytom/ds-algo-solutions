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
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> prefix(n + 1);
    set<char> seen;
    for (int i = 1; i <= n; i++) {
        prefix[i] += prefix[i - 1] + (!seen.count(s[i - 1]));
        seen.insert(s[i - 1]);
    }
    seen.clear();
    int max_val = -1;
    for (int i = n - 1; i >= 1; i--) {
        seen.insert(s[i]);
        // .....i-1|i
        max_val = max(max_val, prefix[i] + (int) seen.size());
    }
    cout << max_val << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
