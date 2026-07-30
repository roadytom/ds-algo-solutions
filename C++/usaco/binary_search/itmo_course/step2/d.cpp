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
https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/D
time: i * cnt + rest
T -> cnt, i -->| rest --> cnt, i --> rest,
(T / (cnt * i + rest)) * cnt --> gain
T  % (cnt * i + rest) = x left time, min(cnt, x / i)

T_min = 0, T_max = 15000 * 1100 = 1,65 10^8
*/
void solve() {
    ll m, n;
    cin >> m >> n;
    v<ll> t(n), z(n), y(n);
    rep(i, 0, n) cin >> t[i] >> z[i] >> y[i];
    // output, T time takes to inflate all ballons
    // assistans: ballons inflated by each of them
    ll left = 0, right = 1e9 + 5;
    v<ll> work(n);

    auto fill_work_for_each = [&](ll time) {
        ll cnt = 0;
        bool fill_zero = false;
        for (int i = 0; i < n; i++) {
            if (fill_zero) work[i] = 0;
            ll gain = time / (z[i] * t[i] + y[i]) * z[i];
            ll left_over_time = time % (z[i] * t[i] + y[i]);
            gain += min(z[i], left_over_time / t[i]);
            if (cnt + gain >= m) {
                fill_zero = true;
                ll req = m - cnt;
                work[i] = req;
            } else {
                work[i] = gain;
            }
            cnt += work[i];
        }
    };
    auto check = [&](ll time) {
        fill_work_for_each(time);
        return accumulate(all(work), 0LL) >= m;
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
    fill_work_for_each(left);
    for (auto &w: work) cout << w << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
