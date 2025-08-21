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
    vector<pii> vals{{2, 1}, {1, 3}, {4, 6}, {2, 10}};
    int min_count = INT_MAX;
    for (int one_count = 0; one_count <= 2; one_count++) {
        for (int three_count = 0; three_count <= 1; three_count++) {
            for (int six_count = 0; six_count <= 4; six_count++) {
                for (int ten_count = 0; ten_count <= 2; ten_count++) {
                    int option = n - (one_count * 1 + three_count * 3 + six_count * 6 + ten_count * 10);
                    if (option >= 0 && (option % 15) == 0) {
                        min_count = min(min_count, one_count + three_count + six_count + ten_count + option / 15);
                    }
                }
            }
        }
    }
    cout << min_count << endl;
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
