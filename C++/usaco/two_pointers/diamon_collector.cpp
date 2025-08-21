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
    ull k;
    cin >> k;
    v<ull> d(n);
    rep(i, 0, n) cin >> d[i];
    v<ull> dp(n + 1);
    sort(all(d));
    int left = 0, right = 0;
    while (right < n) {
        ull diff = d[right] - d[left];
        while (left <= right && diff > k) {
            left++;
            diff = d[right] - d[left];
        }
        dp[right + 1] = max(dp[right], (1ULL * right - left + 1));
        right++;
    }

    right = n - 1, left = n - 1;
    ull ans = 0;
    debug(d);
    debug(dp);
    while (left >= 0) {
        ull diff = d[right] - d[left];
        while (left <= right && diff > k) {
            right--;
            diff = d[right] - d[left];
        }
        ans = max(ans, dp[left] + right - left + 1);
        left--;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("diamond.in", "r", stdin); // read from input.txt
    freopen("diamond.out", "w", stdout); // write to output.txt
    solve();
    return 0;
}
