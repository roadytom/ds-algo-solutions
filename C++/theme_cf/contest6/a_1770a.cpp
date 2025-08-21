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

*/
void solve1() {
    int N, M;
    cin >> N >> M;
    priority_queue<int, vector<int>, greater<int> > pq;
    rep(i, 0, N) {
        int x;
        cin >> x;
        pq.push(x);
    }
    rep(j, 0, M) {
        int x;
        cin >> x;
        pq.pop();
        pq.push(x);
    }
    ll sum = 0;
    while (!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    cout << sum << endl;
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> a(N), b(M);
    rep(i, 0, N) cin >> a[i];
    rep(j, 0, M) cin >> b[j];
    ll sum = b[M - 1];
    for (int i = 0; i < M - 1; i++) {
        a.push_back(b[i]);
    }
    sort(rall(a));
    rep(i, 0, N - 1) sum += a[i];
    cout << sum << endl;
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
