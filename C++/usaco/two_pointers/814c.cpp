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

int solve_for_each(const string &s, int m, char color) {
    int left = 0, right = 0;
    int window_count = 0;
    int max_window_count = 0;
    while (right < len(s)) {
        if (s[right] == color) {
            window_count++;
        }
        if (right - left + 1 - window_count > m) {
            if (s[left] == color) window_count--;
            left++;
        }
        max_window_count = max(max_window_count, right - left + 1);
        right++;
    }
    return max_window_count;
}

/**

*/
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    v<v<int> > dp(n + 1, v<int>(26));
    for (int i = 1; i <= n; i++) {
        for (int c = 0; c < 26; c++) {
            dp[i][c] = solve_for_each(s, i, c + 'a');
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int m;
        char c;
        cin >> m >> c;
        cout << dp[m][c - 'a'] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
