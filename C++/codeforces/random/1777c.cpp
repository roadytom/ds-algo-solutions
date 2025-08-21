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
const int M = 1e5;
vector<int> factors[M + 1];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> &curr_factors = factors[m];
    rep(i, 0, n) cin >> a[i];
    sort(all(a));
    int left = 0, right = 0;
    map<int, int> counter;
    int topic_covered = 0;
    int ans = INT_MAX;
    while (right < n) {
        for (int factor: factors[a[right]]) {
            if (factor <= m) {
                counter[factor]++;
                if (counter[factor] == 1) {
                    topic_covered++;
                }
            }
        }
        while (left <= right && topic_covered >= m) {
            ans = min(ans, a[right] - a[left]);
            for (int factor: factors[a[left]]) {
                if (factor <= m) {
                    counter[factor]--;
                    if (counter[factor] == 0) {
                        topic_covered--;
                    }
                }
            }
            left++;
        }
        right++;
    }
    cout << ((ans == INT_MAX) ? -1 : ans) << endl;
}

int main() {
    for (int num = 1; num <= M; num++) {
        for (int j = num; j <= M; j += num) {
            factors[j].push_back(num);
        }
    }
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
