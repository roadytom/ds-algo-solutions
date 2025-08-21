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
    int n;
    cin >> n;
    ll k;
    cin >> k;
    v<int> a(n);
    rep(i, 0, n) cin >> a[i];
    v<ll> h(n);
    rep(i, 0, n) cin >> h[i];
    if (n == 1) {
        cout << (a[0] <= k) << endl;
        return;
    }
    int left = 0, right = 1;
    ll window_sum = a[left];
    int max_len = (a[left] <= k);
    while (right < n) {
        if (h[right - 1] % h[right] != 0) {
            left = right;
            window_sum = 0;
        }

        window_sum += a[right];

        while (left <= right && window_sum > k) {
            window_sum -= a[left];
            left++;
        }
        max_len = max(max_len, right - left + 1);
        right++;
    }
    cout << max_len << endl;
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
