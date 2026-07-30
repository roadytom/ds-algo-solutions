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
const double error = 1e-7;

void solve() {
    int n, k;
    cin >> n >> k;
    v<int> arr(n);
    rep(i, 0, n) cin >> arr[i];
    double left = 0, right = 1e10 + 10;
    auto check = [&](double len) {
        ll cnt = 0;
        for (auto num: arr) {
            cnt += (int) (1.0 * num / len);
            if (cnt >= k) return true;
        }
        return false;
    };
    // while (right - left > error) {
    for (int i = 0; i < 100; i++) {
        double mid = left + (right - left) / 2;
        if (check(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    cout << fixed << setprecision(10) << endl;
    cout << right << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
