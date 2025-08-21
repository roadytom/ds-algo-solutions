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
    string s;
    cin >> s;
    int one = 0, zero = 0;
    for (char c: s) {
        if (c == '0') zero++;
        else one++;
    }
    int n = (int) s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (one == 0) {
                cout << n - i << endl;
                return;
            }
            one--;
        } else {
            if (zero == 0) {
                cout << n - i << endl;
                return;
            }
            zero--;
        }
    }
    cout << 0 << endl;

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
