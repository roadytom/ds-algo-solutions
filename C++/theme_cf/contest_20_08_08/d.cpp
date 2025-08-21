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
struct point {
    int x, y;
};

void solve() {
    int n;
    cin >> n;
    vector<point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    map<pair<int, int>, ll> kandb;
    map<int, ll> ys;
    map<int, ll> xs;
    ll ans = 0;
    for (auto &point: points) {
        int k1 = 1;
        int b1 = point.y - point.x;
        pair<int, int> option1{k1, b1};
        ans += kandb[option1];
        int k2 = -1;
        int b2 = point.y + point.x;
        pair<int, int> option2{k2, b2};
        ans += kandb[option2];
        ans += ys[point.y];
        ans += xs[point.x];
        kandb[option1]++;
        kandb[option2]++;
        ys[point.y]++;
        xs[point.x]++;
    }
    cout << 2LL * ans << endl;
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
