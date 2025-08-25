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
    int R, C;
    cin >> R >> C;
    v<string> data(R);
    for (int i = 0; i < R; i++) {
        cin >> data[i];
    }
    v<v<ll> > prefix(R + 1, v<ll>(C));
    for (int i = 0; i < C; i++) {
        for (int j = 1; j <= R; j++) {
            if (data[j - 1][i] == '*') prefix[j][i] = 0;
            else prefix[j][i] += prefix[j - 1][i] + (data[j - 1][i] == '.');
        }
    }
    ll ans = 0;
    debug(prefix);
    for (int i = 0; i < R; i++) {
        v<ll> dp(C);
        stack<int> st;

        for (int j = 0; j < C; j++) {
            ll height = prefix[i + 1][j];
            while (!st.empty() && prefix[i + 1][st.top()] >= height) {
                st.pop();
            }
            int left_idx = -1;
            if (!st.empty()) {
                left_idx = st.top();
            }
            dp[j] += height * (j - left_idx);
            st.push(j);
        }
        debug(dp);
        st = stack<int>();
        for (int j = C - 1; j >= 0; j--) {
            ll height = prefix[i + 1][j];
            while (!st.empty() && prefix[i + 1][st.top()] >= height) {
                st.pop();
            }
            int right_idx = C;
            if (!st.empty()) {
                right_idx = st.top();
            }
            debug(right_idx, height, j);
            dp[j] += height * (right_idx - j - 1);
            ans = max(ans, dp[j]);
            st.push(j);
        }
        debug(dp);

    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
