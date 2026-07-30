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
https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/E
*/
void solve() {
    double c;
    cin >> c;
    auto greater = [&](double x) {
        return x * x + sqrt(x) >= c;
    };
    double lo = 0.0, hi = 1e8 + 5;

    for (int i = 0; i < 100; i++) {
        double mid = lo + (hi - lo) / 2;
        if (greater(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << fixed << setprecision(20) << lo << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
