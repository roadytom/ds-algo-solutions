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
    v<int> a(n);
    rep(i, 0, n) cin >> a[i];
    ll left = 1, right = 1e14 + 5;
    auto check = [&](ll max_sum) {
        ll curr_sum = 0;
        ll segment = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] > max_sum) return false;
            curr_sum += a[i];
            if (curr_sum > max_sum) {
                segment++;
                curr_sum = a[i];
            }
            if (segment > k) return false;
        }
        return true;
    };
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (check(mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << left << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
