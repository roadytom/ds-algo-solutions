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
    v<ll> r(n);
    v<ll> x(n);
    rep(i, 0, n)
        cin >> x[i] >> r[i];
    stack<pair<double, double> > st;
    auto get_r = [&](pair<double, double> d, int idx) {
        auto &[prev_x, prev_r] = d;
        return (x[idx] - prev_x) * (x[idx] - prev_x) / (prev_r * 4);
    };
    v<double> final_rs(n);
    for (int i = 0; i < n; i++) {
        double max_r = r[i];
        while (!st.empty()) {
            auto curr = st.top();
            double touching_r = get_r(curr, i);
            max_r = min(max_r, touching_r);
            if (curr.s <= max_r) {
                st.pop();
            } else {
                break;
            }
        }
        final_rs[i] = max_r;
        st.emplace(x[i], max_r);
    }
    const int PRECISION = 3;
    cout << fixed << setprecision(PRECISION);
    for (int i = 0; i < n; i++) cout << final_rs[i] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
