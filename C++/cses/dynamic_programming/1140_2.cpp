/**
 * 1142_2
 * https://codeforces.com/
 */
#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

#define len(x) static_cast<int>((x).size())

// Constants
constexpr long long MOD = 1e9 + 7;
constexpr long long INF = 1e18;
constexpr long long MAXN = 2e6 + 5; // for factorial precomputation etc.
constexpr long long mx = 1e9;
const int START = 0, END = 1;

struct Event {
    int pos;
    int type;
    int id;
    int r;

    bool operator<(const Event &b) const {
        return make_pair(pos, type) < make_pair(b.pos, b.type);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<Event> events;
    for (int i = 0; i < n; i++) {
        int left, right, r;
        cin >> left >> right >> r;
        events.push_back(Event{left, START, i, r});
        events.push_back(Event{right, END, i, r});
    }
    sort(events.begin(), events.end());
    long long ans = 0;
    vector<long long> would_take(n);
    for (auto &e: events) {
        int type = e.type;
        if (type == START) {
            would_take[e.id] = ans + e.r;
        } else {
            ans = max(ans, would_take[e.id]);
        }
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
