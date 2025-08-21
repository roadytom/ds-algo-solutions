#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
/**
red, blue, num
click red -> num * 2
blue -> num - 1
if num < 0 -> terminate

start = n
target = m
find MIN CLICKS to achieve target
*/
void solve() {
    ll n, m;
    cin >> n >> m;
    queue<ll> q;
    q.push(n);
    int level = 0;
    bool found = false;
    vector<bool> visited(max(n + 1, 2 * m + 1));
    visited[n] = true;
    while (!found) {
        level++;
        int sz = (int) q.size();
        // debug(q);
        while (sz--) {
            ll curr = q.front();
            q.pop();
            if (curr == 0) continue;
            if (curr == m) {
                found = true;
                break;
            }
            if (curr > m) {
                if (!visited[curr - 1]) {
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }
            } else {
                if (!visited[2 * curr]) {
                    visited[2 * curr] = true;
                    q.push(2 * curr);
                }
                if (!visited[curr - 1]) {
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }
            }
        }
    }
    cout << level - 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
