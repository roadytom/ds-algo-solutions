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
vector<int> h, pg, ng, fval;

// ---- segment tree over positions: max f value, point update ----
vector<int> seg;

void upd(int nd, int l, int r, int p, int v) {
    if (l == r) {
        seg[nd] = max(seg[nd], v);
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m) upd(nd << 1, l, m, p, v);
    else upd(nd << 1 | 1, m + 1, r, p, v);
    seg[nd] = max(seg[nd << 1], seg[nd << 1 | 1]);
}

int qry(int nd, int l, int r, int ql, int qr) {
    if (ql > qr || qr < l || r < ql) return 0; // empty / disjoint
    if (ql <= l && r <= qr) return seg[nd];
    int m = (l + r) >> 1; 
    return max(qry(nd << 1, l, m, ql, qr),
               qry(nd << 1 | 1, m + 1, r, ql, qr));
}

void solve() {
    cin >> n;
    h.resize(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    pg.assign(n, -1);
    ng.assign(n, n);
    seg.assign(4 * n, 0);
    fval.assign(n, 0);

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
    sort(ord.begin(), ord.end());

    int ans = 0;
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && ord[i].first == ord[j].first) ++j; // one equal-height group

        for (int t = i; t < j; ++t) {
            // compute
            int p = ord[t].second;
            int lb = qry(1, 0, n - 1, pg[p] + 1, p - 1); // left territory
            int rb = qry(1, 0, n - 1, p + 1, ng[p] - 1); // right territory
            fval[p] = 1 + max(lb, rb);
            ans = max(ans, fval[p]);
        }
        // publish only after the group
        for (int t = i; t < j; ++t) {
            int p = ord[t].second;
            upd(1, 0, n - 1, p, fval[p]);
        }
        i = j;
    }
    cout << ans << endl;
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
