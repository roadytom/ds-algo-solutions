#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

// Use long long for potentially large numbers
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Base case: n=2. No operators are inserted.
    if (n == 2) {
        cout << s << endl;
        return;
    }

    ll min_overall_result = LLONG_MAX;

    // Loop to choose which adjacent pair of digits forms a two-digit number.
    // 'i' is the index of the first digit of the two-digit number.
    for (int i = 0; i < n - 1; ++i) {
        vector<ll> numbers;
        // Digits before the pair
        for (int j = 0; j < i; ++j) {
            numbers.push_back(s[j] - '0');
        }
        // The two-digit number
        numbers.push_back(stoll(s.substr(i, 2)));
        // Digits after the pair
        for (int j = i + 2; j < n; ++j) {
            numbers.push_back(s[j] - '0');
        }

        // Dynamic programming to find the minimum expression value.
        int k = numbers.size();
        vector<ll> dp(k + 1, LLONG_MAX);
        dp[0] = 0;

        // A reasonable cap to avoid large products and overflow.
        const ll CAP = 40000;

        for (int i_dp = 1; i_dp <= k; ++i_dp) {
            for (int j_dp = 0; j_dp < i_dp; ++j_dp) {
                // Calculate the product of numbers[j_dp ... i_dp-1]
                ll prod = 1;
                for (int l = j_dp; l < i_dp; ++l) {
                    if (numbers[l] == 0) {
                        prod = 0;
                        break;
                    }
                    // Check for overflow against the CAP before multiplying
                    if (numbers[l] > 0 && prod > CAP / numbers[l]) {
                        prod = LLONG_MAX; // Mark as overflowed
                        break;
                    }
                    prod *= numbers[l];
                }

                if (prod == LLONG_MAX || dp[j_dp] == LLONG_MAX) {
                    continue;
                }

                ll current_val = dp[j_dp] + prod;
                if (current_val < dp[i_dp]) {
                    dp[i_dp] = current_val;
                }
            }
        }

        // Update the overall minimum result
        if (dp[k] < min_overall_result) {
            min_overall_result = dp[k];
        }
    }
    cout << min_overall_result << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
