#include <bits/stdc++.h>
#include <atcoder/segtree>
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

using S = int;
// op: The function to combine two data values (S). We need the minimum.
S op(S a, S b) { return max(a, b); }
// e: The identity element for the op function.
S e() { return 0; }
/**

*/
void maxi(int &a, int b) {
    a = max(a, b);
}

void solve() {
    int n;
    cin >> n;
    v<int> heights(n);
    rep(i, 0, n) cin >> heights[i];
    v<int> next_greater(n, n), prev_greater(n, -1);
    auto fill_greater_indices = [&] {
        // NEXT GREATER
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] <= heights[i]) {
                next_greater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            next_greater[st.top()] = n;
            st.pop();
        }
        // PREV GREATER
        st = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] <= heights[i]) {
                prev_greater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            prev_greater[st.top()] = -1;
            st.pop();
        }
    };
    fill_greater_indices();
    debug(prev_greater, next_greater);
    atcoder::segtree<S, op, e> seg(n);
    v<pii> height_to_idx(n);
    rep(i, 0, n) {
        height_to_idx[i] = mp(heights[i], i);
    }
    sort(all(height_to_idx));
    int max_len = 0;
    int left = 0, right = 0;
    v<int> dp(n);
    while (right < n) {
        while (right < n && height_to_idx[left].f == height_to_idx[right].f) {
            right++;
        }
        for (int i = left; i < right; i++) {
            // PROCESS
            int idx = height_to_idx[i].s;
            dp[idx] = 1 + seg.prod(prev_greater[idx] + 1, next_greater[idx]);
        }
        for (int i = left; i < right; i++) {
            int idx = height_to_idx[i].s;
            seg.set(idx, dp[idx]);
            maxi(max_len, dp[idx]);
        }
        left = right;
    }

    cout << max_len << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
