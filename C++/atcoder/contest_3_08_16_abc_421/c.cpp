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
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define v vector
#define len(x) static_cast<int>((x).size())

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
ll count(string &s1, string &s2) {
    v<ll> misplaced_odd;
    v<ll> misplaced_even;
    for (int i = 0; i < len(s1); i++) {
        if (s1[i] == s2[i]) continue;
        if (i % 2) misplaced_odd.pb(i);
        else misplaced_even.pb(i);
    }
    ll cost = 0;
    for (int i = 0; i < len(misplaced_odd); i++) {
        cost += abs(misplaced_odd[i] - misplaced_even[i]);
    }
    return cost;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string target1;
    string target2;
    v<char> options{'A', 'B'};
    for (int i = 0; i < 2 * n; i++) {
        target1 += options[i % 2];
        target2 += options[(i + 1) % 2];
    }

    cout << min(count(target1, s), count(target2, s)) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
