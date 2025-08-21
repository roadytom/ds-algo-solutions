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
    int n, q;
    cin >> n >> q;
    map<int, int> indices;
    for (int i = 0; i < n; i++) {
        int color;
        cin >> color;
        if (!indices.count(color)) {
            indices[color] = i;
        }
    }
    while (q--) {
        int t;
        cin >> t;
        int idx = indices[t];
        cout << idx + 1 << endl;
        for (auto &p: indices) {
            if (p.second < idx) {
                p.second++;
            }
        }
        indices[t] = 0;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
