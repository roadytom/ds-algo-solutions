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
#define len(x) static_cast<int>((x).size())

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
    ll n, p, l, t;
    cin >> n >> p >> l >> t;
    ll all_tasks = (n + 6) / 7;
    ll left = 1, right = n;
    debug(all_tasks);
    auto get = [&](ll mid, ll threshold) {
        ll days = n - mid + 1;
        ll assignments = min(all_tasks, 2 * days) * t;
        if (assignments >= threshold) return true;
        threshold -= assignments;

        return l * days >= threshold;
    };
    while (left <= right) {
        ll mid = (left + right) / 2;
        // debug(mid, get(mid, p));
        if (get(mid, p)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << right - 1 << endl;
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
