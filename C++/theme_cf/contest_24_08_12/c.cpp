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
#define mp make_pair

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
    cin >> n;
    vector<vector<int> > s(n);
    rep(i, 0, n) {
        string x;
        cin >> x;
        for (char c: x) {
            s[i].push_back(c - '0');
        }
    }
    sort(all(s), [](const auto &a, const auto &b) {
        return a.size() > b.size();
    });
    debug(s);
    map<pii, ll> counter;
    ll ans = n;
    for (auto &vec: s) {
        int sz = (int) vec.size();
        int total_sum = accumulate(all(vec), 0);
        ans += counter[mp(sz, total_sum)];

        int sum = total_sum;
        map<pii, int> news;
        for (int left_size = sz; left_size > sz / 2; left_size--) {
            int req_size = 2 * left_size - sz;
            news[mp(req_size, sum)]++;
            counter[mp(req_size, sum)]++;
            sum -= 2 * vec[left_size - 1];
        }
        debug(news);
        // counter.insert(all(news));
    }
    map<pii, ll> counter2;
    for (auto &vec: s) {
        int sz = (int) vec.size();
        int total_sum = accumulate(all(vec), 0);
        ans += counter2[mp(sz, total_sum)];

        int sum = total_sum;
        map<pii, int> news;
        for (int right_size = sz; right_size > sz / 2; right_size--) {
            int req_size = 2 * right_size - sz;
            news[mp(req_size, sum)]++;
            counter2[mp(req_size, sum)]++;
            sum -= 2 * vec[sz - right_size];
        }
        debug(news);
        // counter2.insert(all(news));
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
