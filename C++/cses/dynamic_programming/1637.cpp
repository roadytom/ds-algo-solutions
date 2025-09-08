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
const int INF = 1e9 + 5;
void solve() {
    int n;
    cin >> n;
    v<int> steps(n + 1, INF);
    steps[0] = 1;
    for (int i = 1; i <= n; i++) {
        string digits = to_string(i);
        for (char c: digits) {
            int d = c - '0';
            if (d == 0) continue;
            steps[i] = min(steps[i], steps[i - d] + 1);
        }
    }
    cout << steps[n] - 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
