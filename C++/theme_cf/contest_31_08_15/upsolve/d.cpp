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

/**
 * Solves a single test case for the Maximal Permutation Sum problem.
 *
 * The core idea is that permutations with the maximum sum S(p) are constructed
 * by starting with [n] and iteratively placing n-1, n-2, ..., 1 at either
 * end of the current sequence. This gives 2^(n-1) such permutations.
 *
 * To find the k-th lexicographically smallest one, we can determine the
 * elements of the permutation from smallest to largest (1, 2, 3, ...).
 *
 * For the current set of `m` available numbers, the smallest number can be
 * placed at the beginning or the end. All permutations starting with the
 * smallest number are lexicographically smaller than those where it's at the end.
 * There are 2^(m-2) permutations of each type.
 *
 * We use this property to decide the position of each number `1, 2, ..., n`
 * one by one.
 */
void solve() {
    int n;
    long long k;
    cin >> n >> k;

    // There are 2^(n-1) optimal permutations. If k is larger, it's impossible.
    // We only need to check for n <= 62, as for larger n, 2^(n-1) exceeds k's max value.
    if (n <= 62 && k > (1LL << (n - 1))) {
        cout << -1 << endl;
        return;
    }

    vector<int> p(n);
    int left_ptr = 0;
    int right_ptr = n - 1;
    int current_num = 1;

    // We decide the position for each number from 1 to n.
    for (int rem_len = n; rem_len > 0; --rem_len) {
        // Base case: only one number left to place.
        if (rem_len == 1) {
            p[left_ptr] = current_num;
            break;
        }

        // Calculate the number of permutations that start with the smallest
        // available element. This is 2^((rem_len-1)-1) = 2^(rem_len-2).
        long long combinations_starting_with_min;
        if (rem_len - 2 >= 62) {
            // If rem_len-2 is large, 2^(rem_len-2) will be larger than any k.
            // Use a large constant to represent this "infinity".
            combinations_starting_with_min = 2e18;
        } else {
            combinations_starting_with_min = 1LL << (rem_len - 2);
        }

        if (k <= combinations_starting_with_min) {
            // If k is in the first half, the smallest number goes to the leftmost available spot.
            p[left_ptr++] = current_num++;
        } else {
            // If k is in the second half, the smallest number goes to the rightmost available spot.
            k -= combinations_starting_with_min;
            p[right_ptr--] = current_num++;
        }
    }

    // Print the resulting permutation.
    for (int i = 0; i < n; ++i) {
        cout << p[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}


ll fast_pow(ll b, ll e) {
    ll ans = 1;
    debug(b, e);

    for (; e; b = b * b, e /= 2)
        if (e & 1) ans = ans * b;
    debug(ans);
    return ans;
}

void solve2() {
    int n;
    cin >> n;
    ll k;
    cin >> k;
    if (n <= 60 && (1LL << (n - 1)) < k) {
        cout << -1 << endl;
        return;
    }
    k--;

    v<int> res(n + 1);
    int left = 1, right = n;
    for (int i = 1; i <= n; i++) {
        int other_elements = n - i - 1;
        ll pow = fast_pow(2, other_elements);
        if (k >= pow) {
            k -= pow;
            res[right--] = i;
        } else {
            res[left++] = i;
        }
        debug(k);
    }
    rep(i, 1, n + 1) cout << res[i] << " ";
    cout << endl;
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
