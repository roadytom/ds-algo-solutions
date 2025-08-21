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
struct Data {
    int prefix_balance;
    int idx;
    char ch;

    bool operator<(const Data &other) const {
        if (prefix_balance != other.prefix_balance) {
            return prefix_balance < other.prefix_balance;
        }
        return idx > other.idx;
    }
};

void solve() {
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<Data> info(n);
    info[0] = Data{0, 0, s[0]};
    int prefix = s[0] == '(';
    assert(prefix == 1);
    for (int i = 1; i < n; i++) {
        info[i] = Data{prefix, i, s[i]};
        prefix += (s[i] == '(' ? 1 : -1);
    }
    sort(all(info));
    debug(info);
    for (int i = 0; i < n; i++) {
        cout << info[i].ch;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
