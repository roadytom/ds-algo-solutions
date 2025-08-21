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
    string s;
    cin >> s;
    ll idx;
    cin >> idx;
    idx--;
    int n = len(s);

    int length = n;
    while (idx - length >= 0) {
        idx -= length;
        length--;
    }
    deque<char> dq;
    auto enough_elements = [&](int i) {
        int chars_left = n - i;
        int size_after_removal = len(dq) - 1;
        return chars_left + size_after_removal >= length;
    };
    for (int i = 0; i < n; i++) {
        char curr = s[i];
        while (!dq.empty() && dq.back() > curr && enough_elements(i)) {
            dq.pop_back();
        }
        dq.pb(curr);
    }
    while (!dq.empty()) {
        if (idx == 0) {
            cout << dq.front();
            break;
        }
        dq.pop_front();
        idx--;
    }
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
