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
    int non_match = 0, match = 0;
    bool odd = n % 2 == 1;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) non_match++;
        else match++;
    }
    string t(n + 1, '0');
    int possible = 1;
    for (int i = non_match; i <= non_match + 2 * match + 1; i++) {
        if (possible || odd) {
            t[i] = '1';
        }
        possible ^= 1;
    }
    cout << t << endl;
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
