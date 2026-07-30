/**
 * b
 * https://codeforces.com/
 */
#include <bits/stdc++.h>

using namespace std;

#define len(x) static_cast<int>((x).size())

// Constants
constexpr long long MOD = 1e9 + 7;
constexpr long long INF = 1e18;
constexpr long long MAXN = 2e6 + 5; // for factorial precomputation etc.

bool check_after_ones(int start, vector<int> &a) {
    int two_and_one = 0;
    while (start < len(a)) {
        if (a[start] == 1 || a[start] == 2) {
            two_and_one++;
        } else {
            two_and_one--;
        }
        if (two_and_one >= 0) {
            break;
        }
        start++;
    }
    return start < len(a) - 1 && two_and_one >= 0;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int first_equal_idx = len(a);
    int first_greater_idx = len(a);
    int ones_count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            ones_count++;
        } else {
            ones_count--;
        }
        if (ones_count == 0 && first_equal_idx == len(a)) {
            first_equal_idx = i;
        }
        if (ones_count > 0 && first_greater_idx == len(a)) {
            first_greater_idx = i;
        }
    }
    if (check_after_ones(first_equal_idx + 1, a) || check_after_ones(first_greater_idx + 1, a)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
