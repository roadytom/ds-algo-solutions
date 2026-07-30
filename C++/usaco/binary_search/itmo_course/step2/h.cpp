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
    string s;
    cin >> s;
    v<int> ns(3);
    rep(i, 0, 3) cin >> ns[i];
    v<int> p(3);
    rep(i, 0, 3) cin >> p[i];
    ll r;
    cin >> r;
    ll left = 0, right = 1e15;
    map<int, int> counter;
    for (char c: s) {
        if (c == 'B')
            counter[0]++;
        else if (c == 'S')
            counter[1]++;
        else
            counter[2]++;
    }
    auto check = [&](ll target) {
        ll money = r;
        for (int i = 0; i < 3; i++) {
            if (counter[i] == 0) continue;
            ll cnt = ns[i] / counter[i];
            ll left_over = ns[i] % counter[i];
            if (cnt >= target) continue;
            ll req_money = ((target - cnt) * counter[i] - left_over) * p[i];
            if (money >= req_money) money -= req_money;
            else return false;
        }
        return true;
    };
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        debug(mid);
        if (check(mid)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << right << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
