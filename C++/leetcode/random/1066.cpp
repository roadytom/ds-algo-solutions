#include <bits/stdc++.h>
#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
class Solution {
public:
    int min_cost = INT_MAX;

    int distance(v<int> &p1, v<int> &p2) {
        int x1 = p1[0], y1 = p1[1], x2 = p2[0], y2 = p2[1];
        return abs(x1 - x2) + abs(y1 - y2);
    }

    void backtrack(int worker_idx, v<v<int> > &workers, v<v<int> > &bikes, v<bool> &visited, int cost) {
        if (worker_idx >= len(workers)) {
            min_cost = min(min_cost, cost);
            return;
        }
        for (int i = 0; i < len(bikes); i++) {
            if (!visited[i]) {
                visited[i] = true;
                backtrack(worker_idx + 1, workers, bikes, visited, cost + distance(workers[worker_idx], bikes[i]));
                visited[i] = false;
            }
        }
    }

    int assignBikes(v<v<int> > &workers, v<v<int> > &bikes) {
        v<bool> visited(len(bikes), false);
        backtrack(0, workers, bikes, visited, 0);
        return min_cost;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution s;
    v<v<int> > workers{
        {
            0, 0
        },
        {
            2, 1
        }
    };
    v<v<int> > bikes{
        {1, 2}, {3, 3}
    };
    debug(s.assignBikes(workers, bikes));
    return 0;
}
