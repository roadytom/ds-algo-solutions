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
    vector<pii> milk_time_count;
    rep(i, 0, n) {
        int cows, milk_time;
        cin >> cows >> milk_time;
        milk_time_count.emplace_back(milk_time, cows);
    }
    sort(all(milk_time_count));
    int left = 0, right = n - 1;
    int min_time = INT_MIN;
    while (left <= right) {
        int min_cows = min(milk_time_count[left].second, milk_time_count[right].second);
        min_time = max(min_time, milk_time_count[left].first + milk_time_count[right].first);
        milk_time_count[left].second -= min_cows;
        if (left != right) milk_time_count[right].second -= min_cows;
        if (milk_time_count[left].second == min_cows) left++;
        if (milk_time_count[right].second == min_cows) right--;
    }
    cout << min_time << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    solve();
    return 0;
}
