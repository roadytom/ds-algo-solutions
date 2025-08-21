#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
#define mp make_pair

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
/**

*/
pii two_sum(int start, int end, int target, const vector<pii> &arr) {
    while (start < end) {
        int curr = arr[start].first + arr[end].first;
        if (curr == target) {
            return mp(start, end);
        } else if (curr > target) {
            end--;
        } else {
            start++;
        }
    }
    return mp(-1, -1);
}

void solve() {
    int n, target;
    cin >> n >> target;
    vector<pii> arr(n);
    rep(i, 0, n) {
        int val;
        cin >> val;
        arr[i] = mp(val, i);
    }
    sort(all(arr));
    for (int i = 0; i < n - 2; i++) {
        auto [fst, snd] = two_sum(i + 1, n - 1, target - arr[i].first, arr);
        if (fst != -1) {
            cout << arr[i].second + 1 << " " << arr[fst].second + 1 << " " << arr[snd].second + 1 << endl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
