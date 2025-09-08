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
#define len(x) static_cast<int>((x).size())

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
    int n = len(s);
    int segment_count = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            segment_count++;
        }
    }
    bool have_zero_one = false;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1] && s[i - 1] == '0' && s[i] == '1') {
            have_zero_one = true;
            break;
        }
    }
    cout << segment_count - (int)(have_zero_one) << endl;
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
