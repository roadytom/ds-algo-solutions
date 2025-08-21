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
/**

*/
bool solve() {
    string p, s;
    cin >> p >> s;

    int buffer = 0;
    char prev = '$';
    int j = 0, i = 0;
    int p_size = len(p), s_size = len(s);
    do {
        int cnt1 = 1;
        while (i + 1 < p_size && p[i + 1] == p[i]) {
            i++;
            cnt1++;
        }
        int cnt2 = 1;
        while (j + 1 < s_size && s[j + 1] == s[j]) {
            j++;
            cnt2++;
        }
        if (s[j] != p[i] || 2 * cnt1 < cnt2 || cnt1 > cnt2) return false;
        i++, j++;
    } while (i < p_size && j < s_size);
    return i >= p_size && j >= s_size;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        if (solve()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
