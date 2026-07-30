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
#define pb push_back
#define ppb pop_back
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
    v<int> coords(n);
    rep(i, 0, n) cin >> coords[i];
    auto check = [&](ll dist) {
        ll window_sum = 0;
        ll cow = 1;
        for (int i = 1; i < n; i++) {
            window_sum += coords[i] - coords[i - 1];
            if (window_sum >= dist) {
                window_sum = 0;
                cow++;
            }
            if (cow >= k) return true;
        }
        return false;
    };
    ll left = 0LL, right = 1e18;

    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (check(mid)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << right << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
