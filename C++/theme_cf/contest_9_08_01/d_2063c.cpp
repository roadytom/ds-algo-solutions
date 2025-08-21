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
    vector<vector<int> > tree(n + 1);
    vector<ll> degree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    multiset<pair<ll, int> > sorted_list;
    for (int i = 1; i <= n; i++) {
        sorted_list.emplace(degree[i], i);
    }
    ll mans = 0;
    for (int i = 1; i <= n; i++) {
        sorted_list.erase(pair<ll, int>{degree[i], i});
        for (int child: tree[i]) {
            sorted_list.erase(pair<ll, int>{degree[child], child});
            sorted_list.emplace(degree[child] - 1, child);
        }
        mans = max(mans, degree[i] + sorted_list.rbegin()->first - 1);
        for (int child: tree[i]) {
            sorted_list.erase(pair<ll, int>{degree[child] - 1, child});
            sorted_list.emplace(degree[child], child);
        }
        sorted_list.emplace(pair<ll, int>{degree[i], i});
    }
    cout << mans << endl;
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
