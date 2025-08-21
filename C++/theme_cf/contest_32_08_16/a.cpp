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
    ll n, k;
    cin >> n >> k;
    ull x;
    cin >> x;
    v<ull> a(n);
    rep(i, 0, n) cin >> a[i];
    for (int i = 0; i < n; i++) {
        a.pb(a[i]);
    }
    v<ull> prefix_sum(len(a) + 1);
    partial_sum(all(a), prefix_sum.begin() + 1);
    ull total_sum = *prefix_sum.rbegin() / 2;
    if (total_sum < x / k) {
        cout << 0 << endl;
        return;
    }
    auto sum = [&](ll left, ll right) {
        debug(left, right);

        ll elements = right - left + 1;
        ull res = 1ULL * (elements / n) * total_sum;

        left = left % n;

        right = left + elements % n - 1;
        res += (prefix_sum[right + 1] - prefix_sum[left]);
        debug(res);

        return res;
    };
    ll left = 0;
    ll right = n * k - 1;

    while (left <= right) {
        ll mid = (left + right) / 2;
        ull sm = sum(mid, n * k - 1);
        if (sm < x) {
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
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
