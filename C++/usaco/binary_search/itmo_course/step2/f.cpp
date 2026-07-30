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
    string t, p;
    cin >> t >> p;
    v<int> removals(len(t));
    rep(i, 0, len(t)) {
        int x;
        cin >> x;
        removals[i] = x - 1;
    }
    int l = 1, r = len(t);
    map<char, int> p_count;
    map<char, int> t_count;
    for (char c: p) {
        p_count[c]++;
    }
    for (char c: t) {
        t_count[c]++;
    }
    auto check = [&](int cnt) {
        unordered_set<int> removed_indices;
        for (int i = 0; i < cnt; i++) {
            removed_indices.insert(removals[i]);
        }
        string new_string;
        for (int i = 0; i < len(t); i++) {
            if (removed_indices.count(i)) continue;
            new_string += t[i];
        }
        int p1 = 0, p2 = 0;
        while (p1 < len(new_string) && p2 < len(p)) {
            if (new_string[p1] == p[p2]) {
                p1++;
                p2++;
            } else {
                p1++;
            }
        }
        return p2 == len(p);
    };

    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << r << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
