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
    int n;
    cin >> n;
    int alice_perfect = 0, alice_perfect_bob_not = 0, alice_equal = 0;
    int bob_perfect = 0, bob_perfect_alice_not = 0, bob_equal = 0;
    v<int> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }

    v<int> b(n);
    rep(i, 0, n) {
        cin >> b[i];
    }
    priority_queue<pli> hp;
    for (int i = 0; i < n; i++) {
        hp.emplace(a[i] + b[i], i);
    }
    v<bool> taken(n, false);
    int alice = 1;
    ll diff = 0;
    for (int i = 0; i < n; i++) {
        if (alice) {
            while (!hp.empty() && taken[hp.top().s]) {
                hp.pop();
            }
            assert(!hp.empty());
            diff += a[hp.top().s] - 1;
            taken[hp.top().s] = true;
            debug(hp.top());
            hp.pop();
        } else {
            while (!a.empty() && taken[hp.top().s]) {
                hp.pop();
            }
            assert(!hp.empty());
            diff -= (b[hp.top().s] - 1);
            taken[hp.top().s] = true;
            debug(hp.top());
            hp.pop();
        }
        alice ^= 1;
    }
    cout << diff << endl;
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
