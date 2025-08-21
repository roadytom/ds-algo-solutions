#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)

long long try_reverse(int start, int end) {
    ll sum = 0;
    ll mx = 0;
    for (int i = 0; i < (end - start + 1); i++) {
        ll pair = (start + i) * (end - i);
        mx = max(mx, pair);
        sum += pair;
    }
    return sum - mx;
}

/**

*/
void solve() {
    int n;
    cin >> n;
    ll sum = 0;
    ll max_sum = 0;
    for (int i = 1; i <= n; i++) {
        ll res = try_reverse(i, n);
        max_sum = max(max_sum, sum + res);
        sum += i * i;
    }
    cout << max_sum << endl;
}

void brute() {
    int n;
    cin >> n;
    vector<int> perm;
    rep(i, 1, n + 1) perm.push_back(i);
    vector<vector<int> > ans;
    ll mx_ans = 0;
    do {
        ll mx = 0;
        ll sum = 0;
        rep(i, 1, n + 1) {
            ll prod = perm[i - 1] * i;
            mx = max(mx, prod);
            sum += prod;
        }
        if (mx_ans < sum - mx) {
            mx_ans = sum - mx;
            ans.clear();
            ans.push_back(perm);
        } else if (mx_ans == sum - mx) {
            ans.push_back(perm);
        }
    } while (next_permutation(all(perm)));
    debug(ans);
    debug(mx_ans);
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        // brute();
        solve();
    }
    return 0;
}
