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
constexpr ll CAP = LLONG_MAX / 2;
ll solve_dp(const vector<int> &numbers) {
    int size = (int) numbers.size();
    // dp[i] min achievable num from dp[0..i];
    vector<ll> dp(size + 1, CAP);
    dp[0] = 0;
    for (int i = 1; i <= size; i++) {
        ll prod = 1;
        for (int mul_start_idx = i - 1; mul_start_idx >= 0; mul_start_idx--) {
            if (numbers[mul_start_idx] == 0) {
                prod = 0;
            } else {
                if (prod > CAP / numbers[mul_start_idx]) {
                    prod = CAP;
                } else {
                    prod *= numbers[mul_start_idx];
                }
            }
            // if (prod != LLONG_MAX && dp[mul_start_idx] != LLONG_MAX) {
            dp[i] = min(dp[i], dp[mul_start_idx] + prod);
            // }
            if (prod >= CAP) {
                break;
            }
        }
    }
    // debug(numbers);
    // debug(dp);
    return dp[size];
}

/**

*/
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll min_overall_result = LLONG_MAX;
    for (int i = 0; i < n - 1; i++) {
        vector<int> numbers;
        for (int num = 0; num < i; num++) {
            numbers.push_back(s[num] - '0');
        }
        int two_digit = 10 * (s[i] - '0') + s[i + 1] - '0';
        numbers.push_back(two_digit);
        for (int num = i + 2; num < n; num++) {
            numbers.push_back(s[num] - '0');
        }

        ll res = solve_dp(numbers);
        min_overall_result = min(res, min_overall_result);
    }
    cout << min_overall_result << endl;
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
