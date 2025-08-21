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
#define mp make_pair
#define mt make_tuple
#define pb push_back
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

/**

*/
void solve() {
    int hurdle_count, power_count;
    int end_position;
    cin >> hurdle_count >> power_count >> end_position;
    v<tuple<int, int, int> > events;
    rep(i, 0, hurdle_count) {
        int start, end;
        cin >> start >> end;
        events.emplace_back(start, end, 0);
    }
    rep(i, 0, power_count) {
        int pos, power_up;
        cin >> pos >> power_up;
        events.emplace_back(pos, power_up, 1);
    }
    sort(all(events));
    priority_queue<ll> jumps;
    ll curr_jump = 1;
    debug(events);
    for (auto &[a, b, type]: events) {
        if (type == 1) {
            jumps.push(b);
        } else {
            while (!jumps.empty() && curr_jump < b - a + 2) {
                curr_jump += jumps.top();
                jumps.pop();
            }
            if (curr_jump < b - a + 2) {
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << power_count - jumps.size() << endl;
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
