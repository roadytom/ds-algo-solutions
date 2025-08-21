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
    set<int> not_used_nodes;
    for (int i = 1; i <= n; i++) {
        not_used_nodes.insert(i);
    }
    int m;
    cin >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        not_used_nodes.erase(b);
    }
    int node = *not_used_nodes.begin();
    debug(node);
    for (int i = 1; i <= n; i++) {
        if (i != node) {
            cout << node << " " << i << endl;
        }
    }
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
