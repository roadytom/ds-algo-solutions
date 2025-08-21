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
xxxxx
00000
 xxxxxxx
*/
void solve() {
    string a, b;
    cin >> a >> b;
    int longest_match_count = 0;
    for (int i = 0; i < len(b); i++) {
        int idx = 0;
        int match_count = 0;
        for (int j = i; j < len(b); j++) {
            while (idx < len(a) && b[j] != a[idx]) idx++;
            if (idx < len(a)) {
                match_count++;
                idx++;
            } else {
                break;
            }
        }
        longest_match_count = max(longest_match_count, match_count);
    }
    debug(longest_match_count);
    cout << len(a) + len(b) - longest_match_count << endl;
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
