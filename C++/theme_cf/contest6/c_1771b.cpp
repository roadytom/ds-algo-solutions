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
    int n, m;
    cin >> n >> m;
    vector<int> largest_not_possible(n + 1, 0);
    rep(i, 0, m) {
        int x, y;
        cin >> x >> y;
        if (x > y) {
            swap(x, y);
        }
        largest_not_possible[y] = max(largest_not_possible[y], x);
    }
    int left = 1, right = 1;
    ll subarray_count = 0;
    // debug(largest_not_possible);
    while (right <= n) {
        int starting_index = largest_not_possible[right] + 1;
        left = max(left, starting_index);
        subarray_count += right - left + 1;
        right++;
    }
    cout << subarray_count << endl;
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
