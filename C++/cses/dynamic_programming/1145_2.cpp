/**
 * 1145_2
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
vector<int> arr;

void solve() {
    cin >> n;
    arr.resize(n);
    for (int &x: arr) cin >> x;
    vector<int> ps(n, -1);
    {
        stack<pair<int, int> > st;
        st.push({0, -1});
        for (int i = 0; i < n; ++i) {
            while (st.top().first >= arr[i]) st.pop();
            ps[i] = st.top().second;
            st.push({arr[i], i});
        }
    }
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
        dp[i] = (ps[i] == -1 ? 0 : dp[ps[i]]) + 1;
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
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
