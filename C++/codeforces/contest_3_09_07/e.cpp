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
#define len(x) static_cast<int>((x).size())
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define v vector

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
/**

*/
void solve() {
    int n, k;
    cin >> n >> k;
    v<int> prev(n);
    rep(i, 0, n) cin >> prev[i];
    map<int, int> counter;
    for (auto el: prev) counter[el]++;
    int global_mex = -1;
    for (int i = 0; i <= n; i++) {
        if (!counter.count(i)) {
            global_mex = i;
            break;
        }
    }
    debug(global_mex);
    while (k--) {
        v<int> next(n);
        for (int i = 0; i < n; i++) {
            if (prev[i] < global_mex && counter[prev[i]] == 1) {
                next[i] = prev[i];
            } else {
                next[i] = global_mex;
            }
        }
        debug(next);
        bool all_equal = true;
        for (int i = 0; i < n; i++) {
            if (prev[i] != next[i]) {
                all_equal = false;
                break;
            }
        }
        if (all_equal) {
            if (k % 2 == 0) {
                // for (int i = 0; i < n; i++) {
                //     cout << prev[i] << " ";
                // }
                ll sum = accumulate(all(prev), 0LL);
                cout << sum;
                cout << endl;
                return;
            } else {
                // for (int i = 0; i < n; i++) {
                //     cout << next[i] << " ";
                // }
                ll sum = accumulate(all(next), 0LL);
                cout << sum;
                cout << endl;
                return;
            }
        }
        counter.clear();
        for (auto el: next) counter[el]++;
        for (int i = 0; i <= n; i++) {
            if (!counter.count(i)) {
                global_mex = i;
                break;
            }
        }
        prev = next;
    }
    debug(prev);
    // for (int i = 0; i < n; i++) {
    //     cout << prev[i] << " ";
    // }
    ll sum = accumulate(all(prev), 0LL);
    cout << sum;
    cout << endl;
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
