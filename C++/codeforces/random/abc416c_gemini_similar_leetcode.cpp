#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
/**

*/
void solve() {
    int n;
    ll k, x;
    std::cin >> n >> k >> x;

    std::vector<std::string> options(n);
    for (int i = 0; i < n; i++) {
        std::cin >> options[i];
    }

    // First, sort the options to ensure they are in lexicographical order.
    // This is essential for the mathematical logic to work.
    std::sort(options.begin(), options.end());

    std::string result;
    // Adjust x to be 0-indexed (i.e., from 1...n^k to 0...n^k-1).
    // This greatly simplifies the division and modulo arithmetic.
    x--;

    // This loop builds the result string from left to right.
    // 'pos' represents the number of characters we still need to choose.
    for (ll pos = k; pos > 0; --pos) {
        // Calculate the number of combinations possible with the remaining (pos - 1) characters.
        // This value is n^(pos - 1) and represents the "size" of each block of combinations
        // that start with the same prefix.
        ll blockSize = 1;
        for (int i = 0; i < pos - 1; ++i) {
            // We can assume inputs are such that this won't overflow,
            // because the total number of combinations is at least x.
            blockSize *= n;
        }

        // Determine the index of the correct option for the current position.
        // This is done by seeing which block our target 'x' falls into.
        ll optionIndex = x / blockSize;

        // Append the chosen option to our result string.
        result += options[optionIndex];

        // Update x to be the remainder. This effectively "zooms in" on the next
        // block of combinations for the subsequent character.
        x %= blockSize;
    }

    std::cout << result << std::endl;
}

class Solution {
public:
    char chr(int x) {
        return x + '0';
    }

    int ord(char x) {
        return x - '0';
    }

    ll get_count(bool tight, const v<int> &max_num, int idx) {
        ll count = 1;
        if (tight) {
            for (int i = idx; i < len(max_num); i++) {
                count *= max_num[i] - 0 + 1;
            }
        } else {
            for (int i = idx; i < len(max_num); i++) {
                count *= 9;
            }
        }
        return count;
    }

    int findKthNumber(int n, ll k) {
        v<int> options;
        for (int i = 0; i < 10; i++)
            options.pb(i);
        v<int> res;
        v<int> nums;
        while (n != 0) {
            nums.pb(n % 10);
            n /= 10;
        }
        reverse(all(nums));
        // k += get_count(nums, 1);
        // k--;
        bool tight = true;
        rep(pos, 0, len(nums)) {
            int min_digit = 0;
            int max_digit = tight ? nums[pos] : 9;
            for (int digit = min_digit; digit <= max_digit; digit++) {
                bool curr_right = tight & (digit == max_digit);
                ll cnt = get_count(curr_right, nums, pos + 1);
                if (k > cnt) {
                    k -= cnt;
                } else {
                    tight = curr_right;
                    res.pb(digit);
                    k--;
                    break;
                }
            }
        }
        debug(res);
        int ans = 0;
        for (int re: res) {
            ans = 10 * ans + re;
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    debug(s.findKthNumber(13, 2));
    return 0;
}
