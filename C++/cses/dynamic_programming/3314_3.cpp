/**
 * 3314_2
 * https://codeforces.com/
 */
#include <bits/stdc++.h>

using namespace std;

#define len(x) static_cast<int>((x).size())

// Constants
constexpr long long MOD = 1e9 + 7;
constexpr long long INF = 1e18;
constexpr long long MAXN = 2e6 + 5; // for factorial precomputation etc.
int n;
vector<int> h, pg, ng;


void solve() {
    cin >> n;
    h.resize(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    pg.assign(n, -1);
    ng.assign(n, n);

    // walls: nearest STRICTLY greater on each side  (<= pops, so equals are not walls)
    {
        vector<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && h[st.back()] <= h[i]) st.pop_back();
            pg[i] = st.empty() ? -1 : st.back();
            st.push_back(i);
        }
    }
    {
        vector<int> st;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && h[st.back()] <= h[i]) st.pop_back();
            ng[i] = st.empty() ? n : st.back();
            st.push_back(i);
        }
    }

    // process ascending by height: every strictly shorter mountain is already published
    vector<pair<int, int> > ord(n);
    for (int i = 0; i < n; i++) { ord[i] = {h[i], i}; }
    sort(ord.rbegin(), ord.rend());
    vector<int> dp(n, 1);
    for (auto [_, i]: ord) {
        dp[i] = 1 + max((pg[i] == -1) ? 0 : dp[pg[i]], (ng[i] == n) ? 0 : dp[ng[i]]);
    }
    cout << *max_element(dp.begin(), dp.end());
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
