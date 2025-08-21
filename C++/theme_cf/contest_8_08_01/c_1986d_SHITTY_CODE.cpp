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


/**

*/
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<string> all_possible;
    vector<char> signs{'*', '+'};
    ll min_result = LLONG_MAX;
    if (s.find('0') != string::npos && n > 3) {
        min_result = 0;
    }
    function<void(int, bool, vector<ll> &)> dp = [&](int idx, bool pairs_merged, vector<ll> &segments) {



        // base case
        if (idx >= n) {
            if (!pairs_merged) return;
            // debug(curr);
            ll res = accumulate(all(segments), 0LL);
            // if (res < min_result) {
            // debug(segments);
            // }
            min_result = min(min_result, res);
            return;
        }

        ll digit = s[idx] - '0';

        ll old = segments.back();
        // addition
        segments.push_back(digit);
        dp(idx + 1, pairs_merged, segments);
        segments.pop_back();

        // multiply
        if (digit != 0 && old >= LLONG_MAX / digit) {
            return;
        }
        segments[segments.size() - 1] = old * digit;

        dp(idx + 1, pairs_merged, segments);
        segments[segments.size() - 1] = old;

        if (idx < n - 1 && !pairs_merged) {
            digit = 10 * digit + s[idx + 1] - '0';
            // addition
            segments.push_back(digit);
            dp(idx + 2, true, segments);
            segments.pop_back();

            // multiply
            if (digit != 0 &&old >= LLONG_MAX / digit) {
                return;
            }
            segments[segments.size() - 1] = old * digit;

            dp(idx + 2, true, segments);
            segments[segments.size() - 1] = old;
        }
    };
    vector<ll> curr;
    curr.push_back(s[0] - '0');
    dp(1, false, curr);
    curr.pop_back();
    curr.push_back(10 * (s[0] - '0') + s[1] - '0');
    dp(2, true, curr);
    curr.pop_back();
    cout << min_result << endl;
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
