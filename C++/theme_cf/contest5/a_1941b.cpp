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
bool solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    rep(i, 0, n) cin >> arr[i];
    rep(i, 1, n - 1) {
        arr[i] -= 2 * arr[i - 1];
        arr[i + 1] -= arr[i - 1];
        arr[i - 1] = 0;
        if (arr[i] < 0 || arr[i + 1] < 0) return false;
        // debug(arr);
    }
    return arr[n - 2] == 0 && arr[n - 1] == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        if (solve()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
