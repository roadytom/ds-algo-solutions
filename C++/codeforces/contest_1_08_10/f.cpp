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
    ll n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    vector<ll> pa(n + 1);
    for (int i = 0; i < n; i++) {
        pa[i + 1] = pa[i] + (a[i] == '1');
    }
    ll total_sum_pb = 0;
    vector<ll> pb(n + 1);
    for (int i = 0; i < n; i++) {
        pb[i + 1] = pb[i] + (b[i] == '1');
        total_sum_pb += pb[i + 1];
    }

    vector<ll> v_y_values(n);
    for (int y = 1; y <= n; ++y) {
        v_y_values[y - 1] = 2 * pb[y] - y;
    }
    sort(all(v_y_values));
    vector<long long> prefix_sum_v(n + 1);
    for (int i = 0; i < n; i++) {
        prefix_sum_v[i + 1] = prefix_sum_v[i] + v_y_values[i];
    }
    ll total_sum_y = n * (n + 1) / 2;

    ll total_answer = 0;
    for (int i = 1; i <= n; i++) {
        ll k_x = i - 2 * pa[i];
        auto it = upper_bound(all(v_y_values), k_x);
        ll k = distance(v_y_values.begin(), it);

        ll sum_if_all_cost1 = n * (i - pa[i]) + total_sum_y - total_sum_pb;
        ll sum_of_0_was_correct = 0;
        if (k > 0) {
            sum_of_0_was_correct = k * (-k_x) + prefix_sum_v[k];
        }
        total_answer += sum_if_all_cost1 + sum_of_0_was_correct;
    }
    cout << total_answer << endl;
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
