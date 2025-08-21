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
    vector<string> matrix(n);
    rep(i, 0, n) {
        cin >> matrix[i];
    }
    vector<set<int> > sets(n);
    for (int i = 0; i < n; i++) {
        sets[i].insert(i + 1);
    }
    vector<int> degree(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1') {
                degree[j]++;
            }
        }
    }
    vector<pair<int, int>> order;
    for (int i = 0; i < n; i++) {
        order.emplace_back(degree[i], i);
    }
    sort(all(order));
    for (auto &[_, node]: order) {
        for (int row = 0; row < n; row++) {
            if (matrix[row][node] == '1') {
                for (int val: sets[row]) {
                    sets[node].insert(val);
                }
            }
        }
    }


    for (int i = 0; i < n; i++) {
        auto &vals = sets[i];
        cout << (int) vals.size() << " ";
        for (int val: vals) {
            cout << val << " ";
        }
        cout << endl;
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
