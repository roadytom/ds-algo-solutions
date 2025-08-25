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
    v<int> a(n);
    rep(i, 0, n) cin >> a[i];
    stack<pii> st;
    st.emplace(-1, -1);
    v<int> influence_size(n);
    for (int i = 0; i < n; i++) {
        int height = a[i];
        while (st.top().f >= height) st.pop();
        int left_idx = st.top().s;
        influence_size[i] = i - left_idx;
        st.emplace(height, i);
    }
    st = stack<pii>();
    st.emplace(-1, n);
    for (int i = n - 1; i >= 0; i--) {
        int height = a[i];
        while (st.top().f >= height) st.pop();
        int right_idx = st.top().s;
        influence_size[i] += right_idx - i - 1;
        st.emplace(height, i);
    }
    v<int> ans(n);
    for (int i = 0; i < n; i++) {
        int sz = influence_size[i];
        ans[sz - 1] = max(ans[sz - 1], a[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
