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
    v<int> pos(n);
    rep(i, 0, n) cin >> pos[i];
    sort(all(pos));
    auto find_min = [&] {
        // Exception:
        if (pos[n - 2] - pos[0] == n - 2 && pos[n - 1] - pos[n - 2] > 2) {
            return 2;
        }
        if (pos[n - 1] - pos[1] == n - 2 && pos[1] - pos[0] > 2) {
            return 2;
        }
        int left = 0, right = 0;
        int max_cows = 0;

        while (right < n) {
            while (left <= right && pos[right] - pos[left] + 1 > n) {
                left++;
            }
            max_cows = max(max_cows, right - left + 1);
            right++;
        }
        return n - max_cows;
    };
    auto find_max = [&] {
        return max(pos[n - 2] - pos[0] + 1 - (n - 1), pos[n - 1] - pos[1] + 1 - (n - 1));
    };
    cout << find_min() << endl;
    cout << find_max() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("herding.in", "r", stdin); // read from input.txt
    freopen("herding.out", "w", stdout); // write to output.txt
    solve();
    return 0;
}
